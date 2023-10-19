#ifndef __BUTLER_H
#define __BUTLER_H

#define _POSIX_C_SOURCE 200112L

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WIN32
   #define EXPORT __declspec(dllexport)
#else
   #define EXPORT __attribute__((visibility("default"))) __attribute__((used))
#endif

struct butler_params {
   char *model_path;
   char *preprompt;
   char *antiprompt;
   unsigned int seed;
   unsigned int n_ctx;
   unsigned int n_batch;
   unsigned int n_threads;
   unsigned int n_threads_batch;
};

typedef void maid_output_cb(const char *);

EXPORT int butler_start(struct butler_params *m_params);

EXPORT int butler_continue(const char *input, maid_output_cb *maid_output);

EXPORT void butler_stop(void);

EXPORT void butler_exit(void);

#ifdef __cplusplus
}
#endif
#endif
