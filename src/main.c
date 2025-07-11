#include <stdio.h>
#include <windows.h>
#include "../include/modulib.h"

int main() {
    HMODULE lib = LoadLibraryA("plugins/plugin_sample.dll");
    if (!lib) {
        fprintf(stderr, "[ERROR] Failed to load DLL\n");
        return 1;
    }

    GetPluginAPI_Func get_api = (GetPluginAPI_Func)GetProcAddress(lib, "get_plugin_api");
    if (!get_api) {
        fprintf(stderr, "[ERROR] Failed to find get_plugin_api\n");
        FreeLibrary(lib);
        return 1;
    }

    PluginAPI* api = get_api();
    if (api && api->init && api->update && api->shutdown) {
        api->init();
        api->update(0.016f);
        api->shutdown();
    }

    FreeLibrary(lib);
    return 0;
}