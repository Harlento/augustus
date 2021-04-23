#include "games.h"

#include "building/warehouse.h"
#include "building/monument.h"
#include "core/calc.h"
#include "city/constants.h"
#include "city/data_private.h"
#include "city/emperor.h"
#include "city/finance.h"
#include "city/message.h"
#include "city/sentiment.h"
#include "core/config.h"
#include "game/time.h"

#define POPULATION_SCALING_FACTOR 1000
#define BASE_RESOURCE_REQUIREMENT 3

typedef enum {
    G_PLANNING,
    G_STARTING,
    G_ENDING
} games_messages;

games_type ALL_GAMES[MAX_GAMES] = {
    {1, TR_WINDOW_GAMES_OPTION_1, TR_WINDOW_GAMES_OPTION_1_DESC, 1800, 100, 1, 32, 64, 33, {0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,}},
    {2, TR_WINDOW_GAMES_OPTION_2, TR_WINDOW_GAMES_OPTION_2_DESC, 1000, 200, 1, 32, 64, 33, {0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,}},
    {3, TR_WINDOW_GAMES_OPTION_3, TR_WINDOW_GAMES_OPTION_3_DESC, 800, 200, 1, 32, 64, 33, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,}},
    //{4, TR_WINDOW_GAMES_OPTION_4, TR_WINDOW_GAMES_OPTION_4_DESC, 100, 1, 32, 120, 32, {0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,}}
};


games_type *city_games_get_game_type(int id)
{
    for (int i = 0; i <= MAX_GAMES; ++i) {
        if (ALL_GAMES[i].id == id) {
            return &ALL_GAMES[i];
        }
    }
    return 0;
}

int city_games_money_cost(int game_type_id)
{
    games_type *game = city_games_get_game_type(game_type_id);
    if (!game) {
        return 0;
    }
    int cost = game->cost_base + game->cost_scaling * (city_data.population.population / POPULATION_SCALING_FACTOR);
    return cost;
}

int city_games_resource_cost(int game_type_id, resource_type resource)
{
    games_type *game = city_games_get_game_type(game_type_id);
    if (!game) {
        return 0;
    }
    int cost = game->resource_cost[resource] * (BASE_RESOURCE_REQUIREMENT + city_data.population.population / POPULATION_SCALING_FACTOR);
    return cost;
}


static void post_games_message(int type)
{
    int game_id = city_data.games.selected_games_id;
    int message_offset = (game_id - 1) * 3 + type;
    city_message_post(1, message_offset + MESSAGE_NG_GAMES_PLANNED, 0, 0);
}

static void begin_games(void)
{
    games_type *game = city_games_get_game_type(city_data.games.selected_games_id);

    city_data.games.months_to_go = 0;
    city_data.games.games_is_active = 1;
    city_data.games.remaining_duration = game->duration_days;

    post_games_message(G_STARTING);
}

static void end_games(void)
{
    city_data.games.games_is_active = 0;
    city_data.games.remaining_duration = 0;

    city_data.games.months_since_last = 0;

    post_games_message(G_ENDING);
}

void city_games_schedule(int game_id)
{
    games_type *game = city_games_get_game_type(game_id);
    city_emperor_decrement_personal_savings(city_games_money_cost(game_id));

    for (int resource = RESOURCE_MIN; resource < RESOURCE_MAX; resource++) {
        int resource_cost = city_games_resource_cost(game_id, resource);
        if (resource_cost) {
            building_warehouses_remove_resource(resource, resource_cost);
        }
    }

    city_data.games.months_to_go = game->delay_months;
    post_games_message(G_PLANNING);
}

void city_games_decrement_month_counts(void)
{
    city_data.games.months_since_last++;

    if (city_data.games.months_to_go) {
        city_data.games.months_to_go--;
        if (city_data.games.months_to_go == 0) {
            begin_games();
        }
    }
    if (city_data.games.games_1_bonus_months) {
        city_data.games.games_1_bonus_months--;
    }
    if (city_data.games.games_2_bonus_months) {
        city_data.games.games_2_bonus_months--;
    }
    if (city_data.games.games_3_bonus_months) {
        city_data.games.games_3_bonus_months--;
    }
    if (city_data.games.games_4_bonus_months) {
        city_data.games.games_4_bonus_months--;
    }
}

void city_games_decrement_duration(void)
{
    if (city_data.games.remaining_duration && city_data.games.games_is_active) {
        city_data.games.remaining_duration--;
        if (city_data.games.remaining_duration == 0) {
            end_games();
        }
    }
}

int city_games_naval_battle_active(void)
{
    return city_data.games.games_1_bonus_months;
}

int city_games_executions_active(void)
{
    return city_data.games.games_2_bonus_months;
}

int city_games_trade_festival_active(void)
{
    return city_data.games.games_3_bonus_months;
}