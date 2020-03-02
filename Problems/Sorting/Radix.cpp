#include <iostream>
#include <vector>

using std::vector;

void rsort(vector<int>& vec) {
    int _size   = vec.size(), i0, i1;
    int *_begin = &vec[0];
    vector<int> fach0(_size);
    vector<int> fach1(_size);
    int *_begin_0 = &fach0[0];
    int *_begin_1 = &fach1[0];
 
    for(unsigned int bit=0; bit<28; bit++) {
        i0 = 0; i1 = 0;
        for(int i=0; i<_size; i++) {
            if(*(_begin+i) & (1 << bit))    {*(_begin_1+(i1)) = *(_begin+i); i1++;}
            else                            {*(_begin_0+(i0)) = *(_begin+i); i0++;}
        }
        
        for(int i=0; i<i0; i++)             {*(_begin+i)     = *(_begin_0+i);}
        for(int i=0; i<i1; i++)             {*(_begin+i0+i)  = *(_begin_1+i);}
    }
    
    for(unsigned int bit=28; bit<32; bit++) {
        i0 = 0; i1 = 0;
        for(int i=0; i<_size; i++) {
            if(*(_begin+i) & (1 << bit))    {*(_begin_1+(i1)) = *(_begin+i); i1++;}
            else                            {*(_begin_0+(i0)) = *(_begin+i); i0++;}
        }
        
        for(int i=0; i<i0; i++)             {*(_begin+i)     = *(_begin_0+i);}
        for(int i=0; i<i1; i++)             {*(_begin+i0+i)  = *(_begin_1+i);}
    }
    
}

int main() {

    return 0;
}