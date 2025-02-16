#include "translation/common.h"
#include "translation/translation.h"

static translation_string all_strings[] = {
   {TR_NO_PATCH_TITLE, "Atualização 1.0.1.0 não instalada"},
    {TR_NO_PATCH_MESSAGE,
        "Sua versão de Caesar III não tem a atualização 1.0.1.0 instalada. "
        "Você pode baixar a atualização em:\n"
        URL_PATCHES "\n"
        "Continue por seu próprio risco."},
    {TR_MISSING_FONTS_TITLE, "Fontes faltando"},
    {TR_MISSING_FONTS_MESSAGE,
        "Sua instalação de Caesar III precisa de outros arquivos de fontes. "
        "Você pode baixá-las para seu idioma em:\n"
        URL_PATCHES},
    {TR_NO_EDITOR_TITLE, "Editor não instalado"},
    {TR_NO_EDITOR_MESSAGE,
        "Sua versão de Caesar III não possui os arquivos do Editor de Mapas. "
        "Você pode baixá-lo em:\n"
        URL_EDITOR},
    {TR_INVALID_LANGUAGE_TITLE, "Pasta de idioma inválida"},
    {TR_INVALID_LANGUAGE_MESSAGE,
        "A pasta selecionada não contém um pacote de idioma válido. "
        "Verifique o arquivo de registro para ver os erros"},
    {TR_BUILD_ALL_TEMPLES, "Tudo"},
    {TR_BUTTON_OK, "OK"},
    {TR_BUTTON_CANCEL, "Cancelar"},
    {TR_BUTTON_RESET_DEFAULTS, "Redefinir padrões"},
    {TR_BUTTON_CONFIGURE_HOTKEYS, "Configurar atalhos"},
    {TR_CONFIG_TITLE, "Opções de Configurações do Julius"},
    {TR_CONFIG_LANGUAGE_LABEL, "Idioma:"},
    {TR_CONFIG_LANGUAGE_DEFAULT, "(padrão)"},
    {TR_CONFIG_DISPLAY_SCALE, "Escala de exibição:"},
    {TR_CONFIG_CURSOR_SCALE, "Escala do cursor:"},
    {TR_CONFIG_HEADER_UI_CHANGES, "Mudanças de interface"},
    {TR_CONFIG_HEADER_GAMEPLAY_CHANGES, "Mudanças de jogabilidade"},
    {TR_CONFIG_SHOW_INTRO_VIDEO, "Tocar vídeos de abertura"},
    {TR_CONFIG_SIDEBAR_INFO, "Informação extra no painel de controle"},
    {TR_CONFIG_SMOOTH_SCROLLING, "Ativar rolagem suave"},
    {TR_CONFIG_DISABLE_MOUSE_EDGE_SCROLLING, "Desativar rolagem do mapa no limite da tela"},
    {TR_CONFIG_DISABLE_RIGHT_CLICK_MAP_DRAG, "Desativar rolagem do mapa com botão direito do mouse"},
    {TR_CONFIG_VISUAL_FEEDBACK_ON_DELETE, "Ativar indicador visual ao limpar o terreno"},
    {TR_CONFIG_ALLOW_CYCLING_TEMPLES, "Permitir construir cada templo em sequência"},
    {TR_CONFIG_SHOW_WATER_STRUCTURE_RANGE, "Mostrar alcance ao construir reservatórios, fontes e poços"},
    {TR_CONFIG_SHOW_CONSTRUCTION_SIZE, "Mostrar o tamanho da construção ao arrastar"},
    {TR_CONFIG_HIGHLIGHT_LEGIONS, "Realçar legiões focadas pelo mouse"},
    {TR_CONFIG_SHOW_MILITARY_SIDEBAR, "Mostrar barra lateral militar"},
    {TR_CONFIG_FIX_IMMIGRATION_BUG, "Consertar falha durante a imigração na dificuldade máxima"},
    {TR_CONFIG_FIX_100_YEAR_GHOSTS, "Consertar falha dos 'fantasmas' de 100 anos"},
    {TR_HOTKEY_TITLE, "Configurações de teclas de atalho do Julius"},
    {TR_HOTKEY_LABEL, "Tecla de atalho"},
    {TR_HOTKEY_ALTERNATIVE_LABEL, "Alternativa"},
    {TR_HOTKEY_HEADER_ARROWS, "Teclas de seta"},
    {TR_HOTKEY_HEADER_GLOBAL, "Atalhos gerais"},
    {TR_HOTKEY_HEADER_CITY, "Atalhos da cidade"},
    {TR_HOTKEY_HEADER_ADVISORS, "Conselheiros"},
    {TR_HOTKEY_HEADER_OVERLAYS, "Mapa específicos"},
    {TR_HOTKEY_HEADER_BOOKMARKS, "Pontos de referência"},
    {TR_HOTKEY_HEADER_EDITOR, "Editor"},
    {TR_HOTKEY_HEADER_BUILD, "Atalhos de construção"},
    {TR_HOTKEY_ARROW_UP, "Cima"},
    {TR_HOTKEY_ARROW_DOWN, "Baixo"},
    {TR_HOTKEY_ARROW_LEFT, "Esquerda"},
    {TR_HOTKEY_ARROW_RIGHT, "Direita"},
    {TR_HOTKEY_TOGGLE_FULLSCREEN, "Tela Cheia"},
    {TR_HOTKEY_CENTER_WINDOW, "Centralizar"},
    {TR_HOTKEY_RESIZE_TO_640, "Redimensionar para 640x480"},
    {TR_HOTKEY_RESIZE_TO_800, "Redimensionar para 800x600"},
    {TR_HOTKEY_RESIZE_TO_1024, "Redimensionar para 1024x768"},
    {TR_HOTKEY_SAVE_SCREENSHOT, "Capturar tela"},
    {TR_HOTKEY_SAVE_CITY_SCREENSHOT, "Capturar imagem de cidade"},
    {TR_HOTKEY_BUILD_CLONE, "Clonar construção sob o cursor"},
    {TR_HOTKEY_LOAD_FILE, "Carregar jogo"},
    {TR_HOTKEY_SAVE_FILE, "Salvar jogo"},
    {TR_HOTKEY_INCREASE_GAME_SPEED, "Aumentar velocidade do jogo"},
    {TR_HOTKEY_DECREASE_GAME_SPEED, "Reduzir velocidade do jogo"},
    {TR_HOTKEY_TOGGLE_PAUSE, "Dar pausa"},
    {TR_HOTKEY_CYCLE_LEGION, "Circular por legiões"},
    {TR_HOTKEY_ROTATE_MAP_LEFT, "Girar no sentido anti-horário"},
    {TR_HOTKEY_ROTATE_MAP_RIGHT, "Girar no sentido horário"},
    {TR_HOTKEY_SHOW_ADVISOR_LABOR, "Trabalho"},
    {TR_HOTKEY_SHOW_ADVISOR_MILITARY, "Militar"},
    {TR_HOTKEY_SHOW_ADVISOR_IMPERIAL, "Imperial"},
    {TR_HOTKEY_SHOW_ADVISOR_RATINGS, "Índices"},
    {TR_HOTKEY_SHOW_ADVISOR_TRADE, "Comércio Exterior"},
    {TR_HOTKEY_SHOW_ADVISOR_POPULATION, "População"},
    {TR_HOTKEY_SHOW_ADVISOR_HEALTH, "Saúde"},
    {TR_HOTKEY_SHOW_ADVISOR_EDUCATION, "Educação"},
    {TR_HOTKEY_SHOW_ADVISOR_ENTERTAINMENT, "Entretenimento"},
    {TR_HOTKEY_SHOW_ADVISOR_RELIGION, "Religião"},
    {TR_HOTKEY_SHOW_ADVISOR_FINANCIAL, "Finanças"},
    {TR_HOTKEY_SHOW_ADVISOR_CHIEF, "Conselheiro Chefe"},
    {TR_HOTKEY_TOGGLE_OVERLAY, "Alternar Mapa Atual/Padrão"},
    {TR_HOTKEY_SHOW_OVERLAY_WATER, "Mapa de Água"},
    {TR_HOTKEY_SHOW_OVERLAY_FIRE, "Mapa de Fogo"},
    {TR_HOTKEY_SHOW_OVERLAY_DAMAGE, "Mapa de Avarias"},
    {TR_HOTKEY_SHOW_OVERLAY_CRIME, "Mapa de Criminalidade"},
    {TR_HOTKEY_SHOW_OVERLAY_PROBLEMS, "Mapa de Problemas"},
    {TR_HOTKEY_GO_TO_BOOKMARK_1, "Ir para marcador 1"},
    {TR_HOTKEY_GO_TO_BOOKMARK_2, "Ir para marcador 2"},
    {TR_HOTKEY_GO_TO_BOOKMARK_3, "Ir para marcador 3"},
    {TR_HOTKEY_GO_TO_BOOKMARK_4, "Ir para marcador 4"},
    {TR_HOTKEY_SET_BOOKMARK_1, "Definir marcador 1"},
    {TR_HOTKEY_SET_BOOKMARK_2, "Definir marcador 2"},
    {TR_HOTKEY_SET_BOOKMARK_3, "Definir marcador 3"},
    {TR_HOTKEY_SET_BOOKMARK_4, "Definir marcador 4"},
    {TR_HOTKEY_EDITOR_TOGGLE_BATTLE_INFO, "Mostrar informações de batalha"},
    {TR_HOTKEY_EDIT_TITLE, "Nova tecla de atalho"},
    { TR_HOTKEY_EDIT_TITLE, "Pressiona nova tecla de atalho" },
    { TR_BUILDING_ROADBLOCK, "Bloqueio de Estrada" },
    { TR_BUILDING_ROADBLOCK_DESC, "Bloqueio de estrada - impede cidadãos ociosos." },
    { TR_BUILDING_ENGINEER_GUILD, "Guilda de Engenharia" },
    { TR_BUILDING_ENGINEER_GUILD_DESC, "Os engenheiros trabalham incansavelmente, construindo monumentos pela glória de Roma." },
    { TR_BUILDING_GRAND_TEMPLE_ADD_MODULE, "Designa um epíteto no templo" },
    { TR_BUILDING_GRAND_TEMPLE_CERES, "Santuário de Ceres" },
    { TR_BUILDING_GRAND_TEMPLE_NEPTUNE, "Santuário de Netuno" },
    { TR_BUILDING_GRAND_TEMPLE_MERCURY, "Santuário de Mercúrio" },
    { TR_BUILDING_GRAND_TEMPLE_MARS, "Santuário de Marte" },
    { TR_BUILDING_GRAND_TEMPLE_VENUS, "Santuário de Vênus" },
    { TR_BUILDING_PANTHEON, "Panteão" },
    { TR_BUILDING_GRAND_TEMPLE_CERES_DESC, "Santuário de Ceres" },
    { TR_BUILDING_GRAND_TEMPLE_NEPTUNE_DESC, "Santuário de Netuno" },
    { TR_BUILDING_GRAND_TEMPLE_MERCURY_DESC, "Santuário de Mercúrio" },
    { TR_BUILDING_GRAND_TEMPLE_MARS_DESC, "Santuário de Marte" },
    { TR_BUILDING_GRAND_TEMPLE_VENUS_DESC, "Santuário de Vênus" },
    { TR_BUILDING_PANTHEON_DESC, "Panteão" },
    { TR_BUILDING_GRAND_TEMPLE_CERES_BONUS_DESC, "Carroceiros de fazendas se movem 50% mais rápido." },
    { TR_BUILDING_GRAND_TEMPLE_NEPTUNE_BONUS_DESC, "Fontes e reservatórios precisam de menos trabalhadores e têm alcance maior. Navios mercantes se movem 25% mais rápido." },
    { TR_BUILDING_GRAND_TEMPLE_MERCURY_BONUS_DESC, "Caravanas e navios mercantes têm capacidade 50% maior. Caravanas se movem 25% mais rápido." },
    { TR_BUILDING_GRAND_TEMPLE_MARS_BONUS_DESC, "Treina soldados como se fosse um quartel. Permite a construção de quatro fortes adicionais." },
    { TR_BUILDING_GRAND_TEMPLE_VENUS_BONUS_DESC, "Jardins, estátuas e templos reluzem com ainda mais beleza, aumentando a atratividade. Moradias armazenam mais bens e regridem mais devagar." },
    { TR_BUILDING_PANTHEON_BONUS_DESC, "Provê acesso a todos os deuses. Realiza festivais anuais e reduz o custo de manutenção dos templos em 25%." },
    { TR_BUILDING_GRAND_TEMPLE_CERES_MODULE_1_DESC, "Sacerdotes reduzem o cunsumo de comida em 20%." },
    { TR_BUILDING_GRAND_TEMPLE_NEPTUNE_MODULE_1_DESC, "Templos enviam condutores de biga para o hipódromo." },
    { TR_BUILDING_GRAND_TEMPLE_MERCURY_MODULE_1_DESC, "Sacerdotes reduzem o consumo de cerâmica e de móveis em 20%." },
    { TR_BUILDING_GRAND_TEMPLE_MARS_MODULE_1_DESC, "Templos produzem comida em quantidade proporcional ao número de moradias que cobrem e a entregam ao posto de suprimentos." },
    { TR_BUILDING_GRAND_TEMPLE_VENUS_MODULE_1_DESC, "O Santuário produz vinho em quantidade proporcional à população com acesso a templos de Vênus. Templos recolhem e distribuem vinho para as moradias." },
    { TR_BUILDING_GRAND_TEMPLE_CERES_MODULE_2_DESC, "Sacerdotes recolhem e distribuem azeite e uma variedade de comida dos estoques da cidade." },
    { TR_BUILDING_GRAND_TEMPLE_NEPTUNE_MODULE_2_DESC, "Sacerdotes aumentam em 5% a capacidade das moradias. O Santuário provêm abastecimento de água como se fosse um reservatório cheio." },
    { TR_BUILDING_GRAND_TEMPLE_MERCURY_MODULE_2_DESC, "Sacerdotes reduzem em 20% o consumo de vinho e de azeite." },
    { TR_BUILDING_GRAND_TEMPLE_MARS_MODULE_2_DESC, "Sacerdotes reduzem em 10% o consumo de todos os bens." },
    { TR_BUILDING_GRAND_TEMPLE_VENUS_MODULE_2_DESC, "Sacerdotes provêm entretenimento e embelezam as moradias." },
    { TR_BUILDING_PANTHEON_MODULE_1_DESC, "Todos os templos da cidade enviam sacerdotes ao Panteão, aumentando a fé e as bênçãos de seus deuses." },
    { TR_BUILDING_PANTHEON_MODULE_2_DESC, "Moradias com acesso ao Panteão conseguem evoluir um nível a mais." },
    { TR_BUILDING_GRAND_TEMPLE_CERES_DESC_MODULE_1, "Templo de Ceres Promitor" },
    { TR_BUILDING_GRAND_TEMPLE_CERES_DESC_MODULE_2, "Templo de Ceres Reparator" },
    { TR_BUILDING_GRAND_TEMPLE_NEPTUNE_DESC_MODULE_1, "Templo de Neptunus Equester" },
    { TR_BUILDING_GRAND_TEMPLE_NEPTUNE_DESC_MODULE_2, "Templo de Neptunus Adiutor" },
    { TR_BUILDING_GRAND_TEMPLE_MERCURY_DESC_MODULE_1, "Templo de Mercurius Fortunus" },
    { TR_BUILDING_GRAND_TEMPLE_MERCURY_DESC_MODULE_2, "Templo de Mercurius Abundantia" },
    { TR_BUILDING_GRAND_TEMPLE_MARS_DESC_MODULE_1, "Templo de Mars Ultor" },
    { TR_BUILDING_GRAND_TEMPLE_MARS_DESC_MODULE_2, "Templo de Mars Quirinus" },
    { TR_BUILDING_GRAND_TEMPLE_VENUS_DESC_MODULE_1, "Templo de Venus Verticordia" },
    { TR_BUILDING_GRAND_TEMPLE_VENUS_DESC_MODULE_2, "Templo de Venus Genetrix" },
    { TR_BUILDING_PANTHEON_DESC_MODULE_1, "Pantheum Ara Maxima" },
    { TR_BUILDING_PANTHEON_DESC_MODULE_2, "Pantheum Roma Aeterna" },
    { TR_BUILDING_GRAND_TEMPLE_MENU, "Santuário" },
    { TR_BUILDING_WORK_CAMP, "Campo de trabalho" },
    { TR_BUILDING_WORK_CAMP_DESC, "Trabalhadores se reúnem aqui para transportar material de construção aos canteiros de obras." },
    { TR_HEADER_HOUSING, "Habitação" },
    { TR_ADVISOR_HOUSING_ROOM, "Moradias da cidade têm espaço para mais" },
    { TR_ADVISOR_HOUSING_NO_ROOM, "Não há mais espaço nas moradias da cidade." },
    { TR_ADVISOR_RESIDENCES_DEMANDING_POTTERY, "Moradias precisando de cerâmica" },
    { TR_ADVISOR_RESIDENCES_DEMANDING_FURNITURE, "Moradias precisando de móveis" },
    { TR_ADVISOR_RESIDENCES_DEMANDING_OIL, "Moradias precisando de azeite" },
    { TR_ADVISOR_RESIDENCES_DEMANDING_WINE, "Moradias precisando de vinho" },
    { TR_ADVISOR_TOTAL_NUM_HOUSES, "Total de moradias:" },
    { TR_ADVISOR_AVAILABLE_HOUSING_CAPACITY, "Capacidade disponível:" },
    { TR_ADVISOR_TOTAL_HOUSING_CAPACITY, "Capacidade total:" },
    { TR_ADVISOR_ADVISOR_HEADER_HOUSING, "População - Habitação" },
    { TR_ADVISOR_BUTTON_GRAPHS, "Gráficos" },
    { TR_ADVISOR_HOUSING_PROSPERITY_RATING, "Índice de prosperidade de moradias: " },
    { TR_ADVISOR_PERCENTAGE_IN_VILLAS_PALACES, "Porcentagem de população em villas e palácios: " },
    { TR_ADVISOR_PERCENTAGE_IN_TENTS_SHACKS, "Porcentagem de população em barracas e choupanas: " },
    { TR_ADVISOR_AVERAGE_TAX, "Arrecadação média de impostos por moradia: " },
    { TR_ADVISOR_AVERAGE_AGE, "Idade média da população: " },
    { TR_ADVISOR_PERCENT_IN_WORKFORCE, "Porcentagem de população economicamente ativa: " },
    { TR_ADVISOR_BIRTHS_LAST_YEAR, "Nascimentos no ano passado:" },
    { TR_ADVISOR_DEATHS_LAST_YEAR, "Óbitos no ano passado:" },
    { TR_ADVISOR_TOTAL_POPULATION, "Total de residentes" },
    { TR_REQUIRED_RESOURCES, "Materiais entregues para a fase atual:" },
    { TR_BUILDING_GRAND_TEMPLE_CONSTRUCTION_DESC, "A construção do Santuário requer materiais estocados em um armazém, trabalhadores de um campo de trabalho e engenheiros de uma guilda de engenharia." },
    { TR_CONSTRUCTION_PHASE, "Fase da construção:" },
    { TR_ADD_MODULE, "Rededicar templo?" },
    { TR_BUILDING_TEMPLE_MODULE_CONSTRUCTED, "Epíteto outorgado." },
    { TR_BUILDING_CERES_TEMPLE_QUOTE, "Primeira foi Ceres o chão com o arado sulcar\nPrimeira à terra grãos e moles frutos dar\nE primeira aos homens a justa lei outorgar\nTudo é um dom de Ceres!\n-Ovídio, Metamorfoses" },
    { TR_BUILDING_NEPTUNE_TEMPLE_QUOTE, "Nem a ira do mar resta, quando Netuno o tridente abaixa\nacalma as ondas o senhor do pélago.\nE Tritão, cerúleo, flutua à superfície;\nombro envolto em púrpura, o búzio sopra;\ne as vagas e rios ele assim ordena.\n-Ovídio, Metamorfoses" },
    { TR_BUILDING_MERCURY_TEMPLE_QUOTE, "Bois e robustas ovelhas são passíveis de pilhagem,\ntrípodes e castanhas cabeças de cavalos, de aquisição.\nMas a alma de um homem não mais volta \nnem por pilhagem nem por escambo \numa vez perdida por entre seus dentes\n-Homero, Ilíada" },
    { TR_BUILDING_MARS_TEMPLE_QUOTE, "A serviço de Marte forjaram rodas aladas,\nCom que o senhor da guerra exalta\n aos homens e cidades,\nAo som terrível de espanto e raiva.\n-Virgílio, Eneida" },
    { TR_BUILDING_VENUS_TEMPLE_QUOTE, "Ó Vênus, e tu, alado Cupido, ao lado de tua terna mãe,\nQuanto me deleitei!\nQuão real o prazer que alcancei!\nComo no leito senti meu coração derreter!\n-Ovídio, Metamorfoses" },
    { TR_BUILDING_PANTHEON_QUOTE, "Os portões do Olimpo se abrem ao chamar de Júpiter\nPela reunião de seu conselho no céu dos astros\nSeus lugares tomam os deuses numa grande sala\nE lá dos altos se pode olhar a terra inteira.\n-Virgílio, Eneida" },
    { TR_BUILDING_GRAND_TEMPLE_PHASE_1, "(Pódio)" },
    { TR_BUILDING_GRAND_TEMPLE_PHASE_2, "(Pórtico)" },
    { TR_BUILDING_GRAND_TEMPLE_PHASE_3, "(Cela)" },
    { TR_BUILDING_GRAND_TEMPLE_PHASE_4, "(Precinto)" },
    { TR_BUILDING_GRAND_TEMPLE_PHASE_5, "(Dedicação)" },
    { TR_BUILDING_GRAND_TEMPLE_PHASE_1_TEXT, "Os trabalhadores estão construindo um pódio para elevar o templo e garantir uma fundação sólida que resita à passagem do tempo." },
    { TR_BUILDING_GRAND_TEMPLE_PHASE_2_TEXT, "Os artesão estão esculpindo o pórtico, onde ficará o altar de sacrifícios." },
    { TR_BUILDING_GRAND_TEMPLE_PHASE_3_TEXT, "Os engenheiros estão construindo a cela, o interior do templo, que abrigará as imagens sagradas." },
    { TR_BUILDING_GRAND_TEMPLE_PHASE_4_TEXT, "Os trabalhos no precinto já começaram; este será o local onde os fiéis se reunirão para cerimônias públicas ao ar livre." },
    { TR_BUILDING_GRAND_TEMPLE_PHASE_5_TEXT, "Com o Santuário quase completo, os sacerdotes se reúnem para realizar os ritos de consagração." },
    { TR_BUILDING_MENU_TREES, "Árvores" },
    { TR_BUILDING_MENU_PATHS, "Caminhos" },
    { TR_BUILDING_MENU_PARKS, "Parques" },
    { TR_BUILDING_SMALL_POND, "Laguinho" },
    { TR_BUILDING_LARGE_POND, "Lago" },
    { TR_BUILDING_PINE_TREE, "Pinheiro" },
    { TR_BUILDING_FIR_TREE, "Abeto" },
    { TR_BUILDING_OAK_TREE, "Carvalho" },
    { TR_BUILDING_ELM_TREE, "Olmo" },
    { TR_BUILDING_FIG_TREE, "Figueira" },
    { TR_BUILDING_PLUM_TREE, "Ameixeira" },
    { TR_BUILDING_PALM_TREE, "Palmeira" },
    { TR_BUILDING_DATE_TREE, "Tamareira" },
    { TR_BUILDING_PINE_PATH, "Caminho de pinheiros" },
    { TR_BUILDING_FIR_PATH, "Caminho de abetos" },
    { TR_BUILDING_OAK_PATH, "Caminho de carvalhos" },
    { TR_BUILDING_ELM_PATH, "Caminho de olmos" },
    { TR_BUILDING_FIG_PATH, "Caminho de figueiras" },
    { TR_BUILDING_PLUM_PATH, "Caminho de ameixeiras" },
    { TR_BUILDING_PALM_PATH, "Caminho de palmeiras" },
    { TR_BUILDING_DATE_PATH, "Caminho de tamareiras" },
    { TR_BUILDING_BLUE_PAVILION, "Coreto azul" },
    { TR_BUILDING_RED_PAVILION, "Coreto vermelho" },
    { TR_BUILDING_ORANGE_PAVILION, "Coreto laranja" },
    { TR_BUILDING_YELLOW_PAVILION, "Coreto amarelo" },
    { TR_BUILDING_GREEN_PAVILION, "Coreto verde" },
    { TR_BUILDING_SMALL_STATUE_ALT, "Estátua de deusa" },
    { TR_BUILDING_SMALL_STATUE_ALT_B, "Estátua de senador" },
    { TR_BUILDING_OBELISK, "Obelisco" },
    { TR_BUILDING_POND_DESC, "Lagos são abastecidos pelos reservatórios da cidade e provêm água para plantas e animais, além de serem um oásis refrescante e relaxante para a população. Os cidadãos adoram viver perto de um lago." },
    { TR_BUILDING_WINDOW_POND, "Lago" },
    { TR_BUILDING_OBELISK_DESC, "Um monumento imponente, erguido por um antigo rei do Nilo. Os egípcios não estavam usando..." },
    { TR_ADVISOR_FINANCE_LEVIES, "Custos de manutenção" },
    { TR_CONFIRM_DELETE_MONUMENT, "Demolindo este monumento" },
    { TR_SELECT_EPITHET_PROMPT_HEADER, "Selecione um epíteto" },
    { TR_SELECT_EPITHET_PROMPT_TEXT, "Outorgar um epíteto dedica permanentemente o Santuário a um aspecto da divindade, dando poderes divinos aos seus sacerdotes. Esta ação tem um custo de 1000 Dn." },
    { TR_BUILDING_INFO_MONTHLY_LEVY, "/mês" },
    { TR_BUILDING_MESS_HALL, "Posto de suprimentos" },
    { TR_BUILDING_MESS_HALL_DESC, "O posto de suprimentos recolhe comida dos celeiros da cidade para abastecer os soldados nos fortes. Um posto mal abastecido atrasa o recrutamento e prejudica o moral das tropas." },
    { TR_BUILDING_MESS_HALL_FULFILLMENT, "Abastecimento de comida no mês passado:" },
    { TR_BUILDING_MESS_HALL_TROOP_HUNGER, "Os soldados estão: " },
    { TR_BUILDING_MESS_HALL_TROOP_HUNGER_1, "Bem alimentados" },
    { TR_BUILDING_MESS_HALL_TROOP_HUNGER_2, "Alimentados" },
    { TR_BUILDING_MESS_HALL_TROOP_HUNGER_3, "Com fome" },
    { TR_BUILDING_MESS_HALL_TROOP_HUNGER_4, "Com muita fome" },
    { TR_BUILDING_MESS_HALL_TROOP_HUNGER_5, "Morrendo de fome" },
    { TR_BUILDING_MESS_HALL_FOOD_TYPES_BONUS_1, "A dieta variada dos soldados aumenta bastante o moral." },
    { TR_BUILDING_MESS_HALL_FOOD_TYPES_BONUS_2, "A dieta diversificada e nutritiva dos soldados aumenta enormemente o moral." },
    { TR_BUILDING_MESS_HALL_NO_SOLDIERS, "Não há soldados para alimentar." },
    { TR_BUILDING_MESS_HALL_MONTHS_FOOD_STORED, "Meses de comida estocada:" },
    { TR_BUILDING_BARRACKS_FOOD_WARNING, "A falta de comida nos postos de suprimentos está retardando o recrutamento de soldados." },
    { TR_BUILDING_BARRACKS_FOOD_WARNING_2, "O grave desabastecimento dos postos de suprimentos está impedindo o recrutamento de soldados." },
    { TR_BUILDING_LEGION_FOOD_WARNING_1, "Recente falta de comida diminuiu o moral" },
    { TR_BUILDING_LEGION_FOOD_WARNING_2, "Recente falta de comida diminuiu bastante o moral" },
    { TR_BUILDING_LEGION_STARVING, "Falta de comida" },
    { TR_ADVISOR_TRADE_MAX, "Máx" },
    { TR_ADVISOR_TRADE_NO_LIMIT, "Sem limite" },
    { TR_ADVISOR_TRADE_IMPORTABLE, "Importável" },
    { TR_ADVISOR_TRADE_EXPORTABLE, "Exportável" },
    { TR_ADVISOR_LEGION_FOOD_SATISFIED, "Os soldados têm toda a comida de que precisam." },
    { TR_ADVISOR_LEGION_FOOD_NEEDED, "Os soldados precisam de mais comida." },
    { TR_ADVISOR_LEGION_FOOD_CRITICAL, "Os soldados estão passando fome!" },
    { TR_ADVISOR_LEGION_MONTHS_FOOD_STORED, "Meses de comida estocada no posto de suprimentos:" },
    { TR_CITY_MESSAGE_TITLE_MESS_HALL_NEEDS_FOOD, "Soldados famintos" },
    { TR_CITY_MESSAGE_TEXT_MESS_HALL_NEEDS_FOOD, "O posto de suprimentos está com grave falta de comida, afetando negativamente o moral das tropas. Garanta que o posto de suprimentos consiga acessar um celeiro bem estocado." },
    { TR_CITY_MESSAGE_TEXT_MESS_HALL_MISSING, "A cidade perdeu seu posto de suprimentos e as tropas agora estão com fome. Construa um posto de suprimentos imediatamente." },
    { TR_MARKET_SPECIAL_ORDERS_HEADER, "Bens para recolher" },
    { TR_WARNING_NO_MESS_HALL, "Construa um posto de suprimentos primeiro, para alimentar os soldados." },
    { TR_WARNING_MAX_GRAND_TEMPLES, "Apenas dois Santuários podem ser construídos." },
    { TR_CITY_MESSAGE_TITLE_GRAND_TEMPLE_COMPLETE, "Santuário completado" },
    { TR_CITY_MESSAGE_TEXT_GRAND_TEMPLE_COMPLETE, "Sacerdotes e fiéis estão se reunindo no Santuário para os ritos de dedicação. O povo está estasiado diante da majestosidade de teus feitos, e a divindade escolhida te enche de graças." },
    { TR_CITY_MESSAGE_TITLE_MERCURY_BLESSING, "Uma bênção de Mercúrio" },
    { TR_CITY_MESSAGE_TEXT_MERCURY_BLESSING, "Encantado com a tua devoção, Mercúrio abençoa a tua indústria, revelando matérias-primas aos artesãos." },
    { TR_FIGURE_TYPE_WORK_CAMP_WORKER, "Capataz" },
    { TR_FIGURE_TYPE_WORK_CAMP_SLAVE, "Carregador" },
    { TR_FIGURE_TYPE_WORK_CAMP_ENGINEER, "Engenheiro" },
    { TR_FIGURE_TYPE_MESS_HALL_BUYER, "Contramestre" },
    { TR_FIGURE_TYPE_MESS_HALL_COLLECTOR, "Servente" },
    { TR_BUILDING_CERES_TEMPLE_MODULE_DESC, "O Santuário de Ceres mobiliza seus sacerdotes para a distribuição de comida e azeite aos cidadãos famintos." },
    { TR_BUILDING_VENUS_TEMPLE_MODULE_DESC, "O Santuário de Vênus permite que seus sacerdotes distribuam do vinho sagrado aos cidadãos." },
    { TR_BUILDING_MARS_TEMPLE_MODULE_DESC, "O Santuário de Marte mobiliza seus sacerdotes para o abastecimento dos postos de suprimentos com comida." },
    { TR_BUILDING_SMALL_TEMPLE_CERES_NAME, "Templo de Ceres" },
    { TR_BUILDING_SMALL_TEMPLE_NEPTUNE_NAME, "Templo de Netuno" },
    { TR_BUILDING_SMALL_TEMPLE_MERCURY_NAME, "Templo de Mercúrio" },
    { TR_BUILDING_SMALL_TEMPLE_MARS_NAME, "Templo de Marte" },
    { TR_BUILDING_SMALL_TEMPLE_VENUS_NAME, "Templo de Vênus" },
    { TR_FIGURE_TYPE_PRIEST_BUYER, "Sacerdote" },
    { TR_PHRASE_FIGURE_MISSIONARY_EXACT_4, "\"Vou fazer o que puder para acalmar esses bárbaros. Estou certo de que eles irão parar de atacar quando eu conseguir conversar com eles.\"" },
    { TR_CITY_MESSAGE_TITLE_PANTHEON_FESTIVAL, "Um festival anual" },
    { TR_CITY_MESSAGE_TEXT_PANTHEON_FESTIVAL_CERES, "Os fiéis lotam os templos para a celebração da Cerealia, em honra a Ceres. Os fazendeiros oferecem sacrifícios pedindo colheitas abundantes nos próximos anos." },
    { TR_CITY_MESSAGE_TEXT_PANTHEON_FESTIVAL_NEPTUNE, "Hoje celebramos o festival da Neptunalia, em honra a Netuno. Os fiéis constróem cabanas com galhos e folhas e celebram sob o cálido sol do verão." },
    { TR_CITY_MESSAGE_TEXT_PANTHEON_FESTIVAL_MERCURY, "Comerciantes e mercadores aparecem em massa para a celebração da Mercuralia. Navios e armazéns são untados com água benta para que sejam protegidos por Mercúrio." },
    { TR_CITY_MESSAGE_TEXT_PANTHEON_FESTIVAL_MARS, "Os cidadãos se reunem fora da cidade para a celebração da Equirria, em busca das graças de Marte. O ar se enche com o trovão dos cascos e o trepidar das bigas, enquanto os fiéis competem em corridas em homenagem ao deus." },
    { TR_CITY_MESSAGE_TEXT_PANTHEON_FESTIVAL_VENUS, "Os fiéis se reúnem para a celebração da Veneralia, dia sagrado de Vênus. Os cidadãos buscam a deusa, rogando por boa sorte no amor." },
    { TR_TOOLTIP_BUTTON_DELETE_READ_MESSAGES, "Apagar mensagens lidas" },
    { TR_TOOLTIP_BUTTON_MOTHBALL_ON, "Fechar esse edifício" },
    { TR_TOOLTIP_BUTTON_MOTHBALL_OFF, "Abrir esse edifício" },
    { TR_TOOLTIP_BUTTON_ACCEPT_MARKET_LADIES, "Permitir que compradoras do mercado comprem daqui" },
    { TR_TOOLTIP_BUTTON_ACCEPT_TRADE_CARAVAN, "Permitir que caravanas negociem aqui" },
    { TR_TOOLTIP_BUTTON_ACCEPT_TRADE_SHIPS, "Permitir que navios mercantes negociem aqui" },
    { TR_CONFIG_HEADER_CITY_MANAGEMENT_CHANGES, "Administração da Cidade" },
    { TR_BUILDING_LIGHTHOUSE, "Farol" },
    { TR_BUILDING_LIGHTHOUSE_PHASE_1, "(Fundação)" },
    { TR_BUILDING_LIGHTHOUSE_PHASE_2, "(Pedestal)" },
    { TR_BUILDING_LIGHTHOUSE_PHASE_3, "(Torre)" },
    { TR_BUILDING_LIGHTHOUSE_PHASE_4, "(Coroa)" },
    { TR_BUILDING_LIGHTHOUSE_PHASE_1_TEXT, "Os engenheiros estão construíndo uma fundação sólida para suportar o peso de uma grande torre de pedra." },
    { TR_BUILDING_LIGHTHOUSE_PHASE_2_TEXT, "Os pedreiros estão construíndo um pedestal para elevar a chama do farol além do horizonte." },
    { TR_BUILDING_LIGHTHOUSE_PHASE_3_TEXT, "A torre do farol se eleva, mais alta a cada dia, conforme os hábeis pedreiros exercem sua profissão." },
    { TR_BUILDING_LIGHTHOUSE_PHASE_4_TEXT, "Os engenheiros estão dando os toques finais no farol. A qualquer momento, ele brilhará até léguas de distância, guiando os navios de volta para casa." },
    { TR_BUILDING_LIGHTHOUSE_CONSTRUCTION_DESC, "A construção do farol requer materiais estocados em um armazém, trabalhadores de um campo de trabalho, e engenheiros de uma guilda de engenharia." },
    { TR_BUILDING_LIGHTHOUSE_BONUS_DESC, "Navios pesqueiros se movem 10% mais rápido. Tempestades marítimas duram metade do tempo." },
    { TR_EDITOR_ALLOWED_BUILDINGS_MONUMENTS, "Monumentos" },
    { TR_CITY_MESSAGE_TEXT_LIGHTHOUSE_COMPLETE, "A imponente torre de pedra do farol, já completa, assuma sobre o horizonte. Que a sua chama guie os navios de volta para casa até o fim dos tempos." },
    { TR_CITY_MESSAGE_TEXT_PANTHEON_COMPLETE, "O Panteão está pronto. Sua monumentalidade é testemunho ímpar do incrível poder dos deuses e do povo de Roma!" },
    { TR_CITY_MESSAGE_TITLE_MONUMENT_COMPLETE, "Monumento completo" },
    { TR_CITY_MESSAGE_TITLE_NEPTUNE_BLESSING, "Uma bênção de Netuno" },
    { TR_CITY_MESSAGE_TEXT_NEPTUNE_BLESSING, "Em recompensa à devoção de tua cidade, Netuno garante viagem segura aos mercadores por doze meses, período no qual tuas exportações lucrarão metade do preço a mais." },
    { TR_CITY_MESSAGE_TITLE_VENUS_BLESSING, "Uma bênção de Vênus" },
    { TR_CITY_MESSAGE_TEXT_VENUS_BLESSING, "Deleitada pela devoção tão alegremente demonstrada a ela, Vênus concede juventude, saúde e felicidade a teu povo, aumentando o tamanho da população economicamente ativa." },
    { TR_BUILDING_MENU_STATUES, "Estátuas" },
    { TR_BUILDING_MENU_GOV_RES, "Mansões do Governador" },
    { TR_OVERLAY_ROADS, "Estradas" },
    { TR_NO_EXTRA_ASSETS_TITLE, "A pasta de assets não pôde ser encontrada" },
    { TR_NO_EXTRA_ASSETS_MESSAGE,
    "Sua instalação do Caesar 3 não instalou adequadamente a pasta de assets. \
    Novos assets não serão carregados adequadamente.\n \
    Por favor, garanta que um diretório '/assets' exista na última camada de seu diretório de instalação do Caesar 3." },
    { TR_WARNING_WATER_NEEDED_FOR_LIGHTHOUSE, "O Farol deve ser posicionado perto da água" },
    { TR_TOOLTIP_OVERLAY_PANTHEON_ACCESS, "Esta moradia tem acesso a todos os cinco deuses do Panteão" },
    { TR_BUILDING_LEGION_FOOD_BONUS, "A abundância de comida está melhorando o moral" },
    { TR_BUILDING_LEGION_FOOD_STATUS, "Condição da comida" },
    { TR_TOOLTIP_BUTTON_ACCEPT_QUARTERMASTER, "Permitir que o contramestre pegue comida daqui" },
    { TR_WARNING_RESOURCES_NOT_AVAILABLE, "Não é possível adquirir os materiais necessários" },
    { TR_CONFIG_GP_CH_MONUMENTS_BOOST_CULTURE_RATING, "Santuários completos garantem +8 no índice de cultura" },
    { TR_BUTTON_BACK_TO_MAIN_MENU, "Voltar ao menu principal" },
    { TR_LABEL_PAUSE_MENU, "Pausa" },
    { TR_OVERLAY_LEVY, "Custos de manutenção" },
    { TR_TOOLTIP_OVERLAY_LEVY, " denários pagos mensalmente em custos de manutenção" },
    { TR_MAP_EDITOR_OPTIONS, "Configurações do cenário" },
    { TR_RETURN_ALL_TO_FORT, "Tudo" },
};

void translation_portuguese(const translation_string **strings, int *num_strings)
{
    *strings = all_strings;
    *num_strings = sizeof(all_strings) / sizeof(translation_string);
}
