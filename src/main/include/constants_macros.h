#ifndef CONST_H
#define CONST_H

#define GENERIC_ADD_MEMBER(orig, orig_t, add_mem, add, add_t, add_s, count)    \
        orig_t append_##add_t(orig_t orig, add_t add) {                        \
          orig->count++;                                                       \
          if(orig->add_mem)                                                    \
            orig->add_mem                                                      \
              = realloc(orig->add_mem, sizeof(add_s) * orig->count);           \
          else                                                                 \
            orig->add_mem = calloc(1, sizeof(add_s));                          \
          orig->add_mem[orig->count - 1] = add;                                \
          return orig;                                                         \
        }

#endif
