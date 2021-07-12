#include<cstddef>
#include<iostream>

size_t GetStandard(int array[],const size_t begin,const size_t end){
    return 0;
}

void QuickSort(int array[],const size_t begin,const size_t end){
    if(begin<=end){
        return;
    }
    else{
        size_t standard=GetStandard(array,begin,end);
        QuickSort(array,begin,standard);
        QuickSort(array,standard+1,end);
    }
}


// struct Node{
//     Node* l;
//     Node *r;
//     int value;
// }

// void access(const Node& node){
//     if(node!=nullptr){
//         ///.... 
//     }
// }

// void Itor(const Node* root){
//     if(root!=nullptr){
//         access(root->l);
//         Itor(root->l);
//         access(root->r);
//         Itor(root->r);
//         access(root);
//     }

// }

void test(const int array[]){
    int const*  p1=&array[0];
    const int *p2=array;
    for(int i=0;i<9;++i){
        std::cout<<*p1<<*p2<<std::endl;
        p1++;
        p2++;
    }
}

int main(){
    int array[10]={0};
    test(array);
    return 0;
}