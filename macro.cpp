#define COMMAND(NAME)  { #NAME, NAME ## _command }
struct command
{
    char *name;
    void (*function) (void);
};

struct command commands[] =
{
    COMMAND (quit),
    COMMAND (help),
    ...
};

#define WARN_IF(EXP) \
     do { if (EXP) \
             fprintf (stderr, "Warning: " #EXP "\n"); } \
     while (0)

#define SKIP_SPACES(p, limit)  \
     { char *lim = (limit);         \
       while (p < lim) {            \
         if (*p++ != ' ') {         \
           p--; break; }}}

int main()
{
    int *p;
    if (0)
   SKIP_SPACES (p, lim);
}
