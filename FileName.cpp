#include <iostream>

using namespace std;

// �ܬ�ݬڬ�֬��Ӭ� ��ڬެӬ�ݬ��
#define NUM_CHAR (256)

// �Ӭ��ڬ�ݬ֬߬ڬ� ��Ѭ٬߬ڬ�� �٬߬Ѭ�֬߬ڬ� ��ڬެӬ�ݬ��
//�߬ڬج߬ڬ� ��֬Ԭڬ���
//#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

typedef struct trieNode {
    struct trieNode* children[NUM_CHAR];

    // �ܬ�߬�֬Ӭ�� ��ݬ֬ެ֬߬�
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

    //���ެ֬�Ѭ֬� �ܬ�߬�֬Ӭ�� ��ݬ֬ެ֬߬�
    temp->terminal = true;
}

// �Ӭ�٬Ӭ�Ѭ�Ѭ֬� true, �֬�ݬ� �֬��� �����ެ��
bool lastNode(struct trieNode* root)
{
    for (int i = 0; i < NUM_CHAR; i++)
        if (root->children[i])
            return 0;
    return 1;
}

// ��֬ܬ���ڬӬ߬Ѭ� ���߬ܬ�ڬ� �ӬѬ�ڬѬ߬���
void printRec(struct trieNode* root,
    string prefix)
{
    // �ڬ�֬� �����ܬ� ��� ���֬�ڬܬ��
    if (root->terminal)
        cout << prefix << endl;

    for (int i = 0; i < NUM_CHAR; i++)
        if (root->children[i]) {
            char child = 'a' + i;
            printRec(root->children[i],
                prefix + child);
        }
}

// �Ӭ�Ӭ�լڬ� �ӬѬ�ڬѬ߬�� ��� �٬Ѭ�����
int printAutotrie(trieNode* root, const string quest)
{
    struct trieNode* temp = root;
    for (char c : quest) {
        int ind = ((int)c - (int)'a');

        // ���֬�ڬܬ� ��������Ӭ�֬� �� �լ֬�֬Ӭ�
        if (!temp->children[ind])
            return 0;

        temp = temp->children[ind];
    }
    //����ݬ֬լ߬֬� ���Ӭ�Ѭլ֬߬ڬ�
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