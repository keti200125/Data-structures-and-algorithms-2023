#include<iostream>
#include<cstring>
#include<queue>
#include<string>

template<class T>
struct Node
{
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(const T& elem,Node<T>* l=nullptr,Node<T>* r=nullptr):data{elem},left{l},right{r} {}
};

template<class T>
void free(Node<T>* root)
{
    if(root==nullptr)
    {
        return;
    }
    free(root->left);
    free(root->right);
    delete root;

}

template <class T>
void printBT(const std::string &prefix, const Node<T> *t, bool isLeft)
{
    if (t != nullptr)
    {
        std::cout << prefix;

       std::cout << (isLeft ? "|--" : "L--");
        std::cout << t->data << std::endl;

        printBT(prefix + (isLeft ? "|   " : "    "), t->left, true);
        printBT(prefix + (isLeft ? "|   " : "    "), t->right, false);
    }
}

template <class T>
void printTree(const Node<T> *t)
{
    printBT("", t, false);
    std::cout<<std::endl;
}


bool read(const Node<char>* tree,const std::string& str, int i, bool addedOnLevel)
{
    if(!tree)
    {
        return false;
    }

    if(tree->data == str[i])
    {
        i++; // 1
        addedOnLevel=true; 
    }

    if(i==str.size())
    {
        return true;
    }
    if(!tree->left && !tree->right && addedOnLevel)
    {
        i--;
    }
    return read(tree->left,str,i,addedOnLevel) || read(tree->right,str,i,addedOnLevel);

    if(addedOnLevel)
    {
        i--;
        addedOnLevel=false;
    }
}

// return true if there is a path from the root to any vertex that spells word
bool canRead(const Node<char>* tree, const std::string& word, unsigned index)
{
    if(tree == nullptr)
    {
        return false;
    }

    if(word[index] != tree->data)
    {
        return false;
    }
    if(index == word.size() - 1) { return true; }

    return canRead(tree->left, word, index + 1) || canRead(tree->right, word, index + 1);
}

bool readWord(const Node<char>* tree,const std::string& str)
{
    if(str.size()<4)
    {
        throw std::invalid_argument("Invalid word");
        //throw std::logic_error("");
    }
    std::string strLeft;
    std::string strRight;

    for(int i=0;i<str.size();i++)
    {
        if(str[i]<tree->data)
        {
            strLeft+=str[i];
        }
        else
        {
            strRight+=str[i];
        }
    }
    if(strLeft.size() <2 || strRight.size() <2)
    {
        throw std::invalid_argument("Invalid word");
    }
    int cnt=0;
    int cnt2=0;
    bool addedOnLevel=false;
    bool addedOnLevelSnd=false;

  
    return read(tree->right,strRight,cnt2,addedOnLevelSnd) && read(tree->left,strLeft,cnt,addedOnLevel);
  
}

int main()
{
    Node<char>* tree=new Node<char>('F',new Node<char>('B',new Node<char>('A'),new Node<char>
    ('D',new Node<char>('C'),new Node<char>('E'))),new Node<char>('G',nullptr,new Node<char>('I',new Node<char>('H'))));
    printTree(tree);
    // std::string str="DCGIH";
    // std::string strLeft;
    // int leftLen=0;
    // int rightLen=0;
    // std::string strRight;


    // std::cout<<readWord(tree,"BDCGI");

    std::string word = "FGH";
    std::cout << canRead(tree, word, 0);
}