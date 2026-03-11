// scenes/master_key_scene.c
#include "master_key_scene.h"

// Génère le tableau des handlers on_enter
#define ADD_SCENE(prefix, name, id) prefix##_scene_##name##_on_enter,
void (*const master_key_scene_on_enter_handlers[])(void*) = {
#include "master_key_scene_config.h"
};
#undef ADD_SCENE

// Génère le tableau des handlers on_event
#define ADD_SCENE(prefix, name, id) prefix##_scene_##name##_on_event,
bool (*const master_key_scene_on_event_handlers[])(void* context, SceneManagerEvent event) = {
#include "master_key_scene_config.h"
};
#undef ADD_SCENE

// Génère le tableau des handlers on_exit
#define ADD_SCENE(prefix, name, id) prefix##_scene_##name##_on_exit,
void (*const master_key_scene_on_exit_handlers[])(void* context) = {
#include "master_key_scene_config.h"
};
#undef ADD_SCENE

// Initialisation de la configuration du Scene Manager
const SceneManagerHandlers master_key_scene_handlers = {
    .on_enter_handlers = master_key_scene_on_enter_handlers,
    .on_event_handlers = master_key_scene_on_event_handlers,
    .on_exit_handlers = master_key_scene_on_exit_handlers,
    .scene_num = MasterKeySceneNum,
};
