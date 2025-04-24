#include <iostream>

using namespace std;

// ¬Ü¬à¬Ý¬Ú¬é¬Ö¬ã¬ä¬Ó¬à ¬ã¬Ú¬Þ¬Ó¬à¬Ý¬à¬Ó
#define NUM_CHAR (256)

// ¬Ó¬í¬é¬Ú¬ã¬Ý¬Ö¬ß¬Ú¬Ö ¬â¬Ñ¬Ù¬ß¬Ú¬è¬í ¬Ù¬ß¬Ñ¬é¬Ö¬ß¬Ú¬Û ¬ã¬Ú¬Þ¬Ó¬à¬Ý¬à¬Ó
//¬ß¬Ú¬Ø¬ß¬Ú¬Û ¬â¬Ö¬Ô¬Ú¬ã¬ä¬â
//#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

typedef struct trieNode {
    struct trieNode* children[NUM_CHAR];

    // ¬Ü¬à¬ß¬è¬Ö¬Ó¬à¬Û ¬ï¬Ý¬Ö¬Þ¬Ö¬ß¬ä
    bool terminal;
}trieNode;

// 
struct trieNode* createnode(void)
{
    struct trieNode* pNode = new trieNode;
    pNode->terminal = false;

    for (int i = 0; i < NUM_CHAR; i++)
        pNode->children[i] = nullptr;

    return pNode;
}


void trieinsert(struct trieNode** root, const string key)
{
    struct trieNode* temp = *root;

    for (int i = 0; i < key.length(); i++) {
        // CHAR_TO_INDEX(c)
        int ind = ((int)key[i] - (int)'a');
        if (!temp->children[ind])
            temp->children[ind] = createnode();

        temp = temp->children[ind];
    }

    //¬à¬ä¬Þ¬Ö¬é¬Ñ¬Ö¬ä ¬Ü¬à¬ß¬è¬Ö¬Ó¬à¬Û ¬ï¬Ý¬Ö¬Þ¬Ö¬ß¬ä
    temp->terminal = true;
}

// ¬Ó¬à¬Ù¬Ó¬â¬Ñ¬ë¬Ñ¬Ö¬ä true, ¬Ö¬ã¬Ý¬Ú ¬Ö¬ã¬ä¬î ¬á¬à¬ä¬à¬Þ¬à¬Ü
bool lastNode(struct trieNode* root)
{
    for (int i = 0; i < NUM_CHAR; i++)
        if (root->children[i])
            return 0;
    return 1;
}

// ¬â¬Ö¬Ü¬å¬â¬ã¬Ú¬Ó¬ß¬Ñ¬ñ ¬æ¬å¬ß¬Ü¬è¬Ú¬ñ ¬Ó¬Ñ¬â¬Ú¬Ñ¬ß¬ä¬à¬Ó
void printRec(struct trieNode* root,
    string prefix)
{
    // ¬Ú¬ë¬Ö¬ä ¬ã¬ä¬â¬à¬Ü¬å ¬á¬à ¬á¬â¬Ö¬æ¬Ú¬Ü¬ã¬å
    if (root->terminal)
        cout << prefix << endl;

    for (int i = 0; i < NUM_CHAR; i++)
        if (root->children[i]) {
            char child = 'a' + i;
            printRec(root->children[i],
                prefix + child);
        }
}

// ¬Ó¬í¬Ó¬à¬Õ¬Ú¬ä ¬Ó¬Ñ¬â¬Ú¬Ñ¬ß¬ä¬í ¬á¬à ¬Ù¬Ñ¬á¬â¬à¬ã¬å
int printAutotrie(trieNode* root, const string quest)
{
    struct trieNode* temp = root;
    for (char c : quest) {
        int ind = ((int)c - (int)'a');

        // ¬á¬â¬Ö¬æ¬Ú¬Ü¬ã ¬à¬ä¬ã¬å¬ä¬ã¬ä¬Ó¬å¬Ö¬ä ¬Ó ¬Õ¬Ö¬â¬Ö¬Ó¬Ö
        if (!temp->children[ind])
            return 0;

        temp = temp->children[ind];
    }
    //¬á¬à¬ã¬Ý¬Ö¬Õ¬ß¬Ö¬Ö ¬ã¬à¬Ó¬á¬Ñ¬Õ¬Ö¬ß¬Ú¬Ö
    if (lastNode(temp)) {
        cout << quest << endl;
        return 0;
    }
    printRec(temp, quest);
    
}


int main()
{
    struct trieNode* root = createnode();
    trieinsert(&root, "hello");
    trieinsert(&root, "competition");
    trieinsert(&root, "computer");
    trieinsert(&root, "cat");
    trieinsert(&root, "a");
    trieinsert(&root, "comma");
    trieinsert(&root, "communist");
    trieinsert(&root, "communication");
    trieinsert(&root, "compile");

    printAutotrie(root, "comp");
    
       
    return 0;
}