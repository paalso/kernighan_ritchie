// int NKEYSsizeof(keytab) / sizeof(key);
// int PNKEYS  sizeof(pre_keytab) / sizeof(key);

typedef struct key {
    char *word;
    char count;
} key;


key keytab[] = {
    "_Alignas", 0,
    "_Alignof", 0,
    "_Atomic", 0,
    "_Bool", 0,
    "_Complex", 0,
    "_Generic", 0,
    "_Imaginary", 0,
    "_Noreturn", 0,
    "_Static_assert", 0,
    "_Thread_local", 0,
    
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "do", 0,
    "double", 0,
    "else", 0,
    "enum", 0,
    "extern", 0,
    "float", 0,
    "for", 0,
    "goto", 0,
    "if", 0,
    "inline", 0,
    "int", 0,
    "long", 0,
    "register", 0,
    "restrict", 0,
    "return", 0,
    "short", 0,
    "signed", 0,
    "sizeof", 0,
    "static", 0,
    "struct", 0,
    "switch", 0,
    "typedef", 0,
    "union", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0
};

key pre_keytab[] = {
    "#define", 0,
    "#elif", 0,
    "#else", 0,
    "#endif", 0,
    "#error", 0,
    "#if", 0,
    "#ifdef", 0,
    "#ifndef", 0,
    "#include", 0,
    "#line", 0,
    "#pragma", 0,
    "#undef", 0,
    "#warning", 0
};
