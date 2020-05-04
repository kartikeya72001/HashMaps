#include <iostream>
#include<string>
using namespace std;
template<typename T>
class Node
{
public:
    string key;
    T value;
    Node<T>*next;

    Node(string key, T val)
    {
        this->key = key;
        value = val;
        next = NULL;
    }
    ~Node()
    {
        if(next!=NULL){
            delete next;
        }
    }
};
template<typename T>
class Hashtable{
private:
    Node<T>** table;
    int cs;
    int ts;

    int hashFn(string key) //Hash Function to convert alphabet*27%tableSize
    {
        int idx = 0;
        int p = 1;
        for(int j=0;j<key.length();j++)
        {
            idx = idx+(key[j]*p)%ts;
            idx = idx%ts;
            p = (p*27)%ts;
        }
        return idx;
    }
    void rehash()
    {
        Node<T> **old = table;
        ts = 2*ts;
        table = new Node<T>*[ts];

        for(int i=0;i<ts;i++){
            table[i] = NULL;
        }
        cs = 0;

        for(int i=0;i<(ts/2);i++)
        {
            Node<T>*temp = old[i];
            while(temp!=NULL)
            {
                insert(temp->key,temp->value);
                temp=temp->next;
            }
            if(old[i]!=NULL){
                delete old[i];
            }
        }
        delete [] old;
    }

public:
    Hashtable(int ts = 7)
    {
        this->ts = ts;
        table = new Node<T>*[ts]; //Allocation of array for hashTable
        cs = 0;
        for(int i=0;i<ts;i++)
        {
            table[i] = NULL;
        }
    }

    void insert(string key, T value)
    {
        int idx = hashFn(key);
        Node<T>* n = new Node<T>(key,value);

        n->next = table[idx];
        table[idx] = n;
        cs++;

        float lf = cs/(1.0*ts);
        if(lf>0.7)
            rehash();
    }

    void print()
    {
        for(int i=0;i<ts;i++)
        {
            cout<<"Bucket "<<i<<" --> ";
            Node<T> *temp = table[i];
            while(temp!=NULL)
            {
                cout<<temp->key<<" --> ";
                temp = temp->next;
            }
            cout<<endl;
        }
        cout<<endl;
    }

    T* search(string key)
    {
        int idx = hashFn(key);
        Node<T> *temp = table[idx];
        while(temp!=NULL)
        {
            if(temp->key==key)
                return &temp->value;
            temp=temp->next;
        }
        return NULL;
    }

    void erase(string key)
    {
        if(search(key)!=NULL)
        {
            int idx = hashFn(key);
            Node<T>* temp = table[idx];
            if(temp->key == key) //Erase if node is at head
            {
                table[idx] = temp->next;
                delete temp;
                cs--;
                return;
            }
            while(temp->next!=NULL)
            {
                if(temp->next->key==key)
                    break;
                temp=temp->next;
            }
            if(temp->next == NULL) //Erase node if it is at Tail
            {
                Node<T>* prev = temp;
                prev->next = NULL;
                temp = temp->next;
                delete temp;
                cs--;
                return;
            }
            Node<T>* prev = temp; //Erase for anyother position(nth)
            temp=temp->next;
            prev->next = temp->next;
            delete temp;
            cs--;
            return;
        }
    }
};
