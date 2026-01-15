
class gapBuffer{

    char*  buf;
    char* bufstr;
    char* bufend;
    char* gapstr;
    char* gapend;

    public:

    gapBuffer(int gapSize);

    ~gapBuffer();

    void insertChar(char c);

    void deleteChar();

    void growGap();

    void moveLeft();

    void moveRight();

    void moveCursor(char *position);

    void readFile();

    void writeFile();

};
