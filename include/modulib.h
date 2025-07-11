#ifndef MODULIB_H
#define MODULIB_H

#ifdef _WIN32
#ifdef EXPORTING_PLUGIN
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif
#else
#define EXPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct {
        void (*init)(void);
        void (*update)(float delta);
        void (*shutdown)(void);
    } PluginAPI;

    typedef PluginAPI* (*GetPluginAPI_Func)(void);

#ifndef EXPORTING_PLUGIN
    EXPORT PluginAPI* get_plugin_api(void);
#endif

#ifdef __cplusplus
}
#endif

#endif // MODULIB_H