#include "stdio.h"
#include "stdlib.h"
#include "modulib.h"

static void plugin_init(void) { printf("init\n"); }
static void plugin_update(float delta) { printf("update %.3f\n", delta); }
static void plugin_shutdown(void) { printf("shutdown\n"); }

static PluginAPI api = {
    .init = plugin_init,
    .update = plugin_update,
    .shutdown = plugin_shutdown
};

EXPORT PluginAPI* get_plugin_api(void) {
    return &api;
}
