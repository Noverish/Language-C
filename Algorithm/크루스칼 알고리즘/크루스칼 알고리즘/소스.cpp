#include <stdio.h> 

#define MAX_VERTEX 100 
#define MAX_ELEMENT 100 

int parent[MAX_VERTEX]; 
int num[MAX_VERTEX]; 

typedef struct { 
    int v; // ����1 
    int u; // ����2 
    int key; // ������ ����ġ 
}Element; 

typedef struct { 
    Element heap[MAX_ELEMENT]; 
    int heap_size; 
}HeapType; 

void InitHeap(HeapType *h) 
{ 
    h->heap_size=0; 
} 
void InsertHeap(HeapType *h,Element item) 
{ 
    int i; 
    i=++(h->heap_size); 

    while(i != 1 && item.key < h->heap[i/2].key) // �θ���� �� 
    { 
        h->heap[i]=h->heap[i/2]; 
        i/=2; 
    } 

    h->heap[i]=item; 
} 

Element DeleteHeap(HeapType *h) 
{ 
    int parent=1,child=2; 
    Element data,temp; 

    data = h->heap[parent]; 
    temp = h->heap[(h->heap_size)--]; // ������ ���� size ���� 

    while(child <= h->heap_size) 
    { 
         //�ڽ� ��尣 ���� �� ��  
        if((child < h->heap_size) && (h->heap[child].key) > h->heap[child+1].key)  
            child++; 
         
        if(temp.key <= h->heap[child].key) break; 

        h->heap[parent] = h->heap[child]; 
        parent = child; 
        child *= 2; // ���� �ڽ� ���� �� 
    } 

    h->heap[parent]=temp; 
    return data; 
} 

void InitUF(void) // ���� ���� �ʱ�ȭ 
{ 
    int i; 
    for(i=0;i<MAX_VERTEX;i++) 
    { 
        parent[i]=-1; 
        num[i]=1; 
    } 
} 

int SetFind(int v) // v�� ���ϴ� ������ ��ȯ�Ѵ� 
{ 
    int i,p,temp; 

    for(i=v;(p=parent[i])>=0;i=p); // ����v�� ��Ʈ�� ã�´� 
     
    temp=i; // ���� v�� �����ϴ� ������ ��ǥ ����  
      
    for(i=v;(p=parent[i])>=0;i=p)  
        parent[i]=temp; // ������ ��� ���ҵ��� �θ� s�� ���� 

    return temp; 
} 

void SetUnion(int v1,int v2) // �ΰ��� ���Ұ� ���� ������ ��ģ�� 
{ 
    if(num[v1] < num[v2]) // �ڽ��� ������ �� 
    { 
        parent[v1]=v2; // �θ� ���� 
        num[v1]+=num[v2]; 
    } 
    else 
    { 
        parent[v2]=v1; // �θ� ���� 
        num[v2]+=num[v1]; 
    } 
} 

void InsertHeapEdge(HeapType *h,int v,int u,int weight) 
{ 
    Element node; 
    node.v=v; 
    node.u=u; 
    node.key=weight; 

    InsertHeap(h,node); 
} 

int kruskal(int n) 
{ 
    Element e; 
    HeapType h; 
    int uSet,vSet,edgeCount=0,sum=0; 

    InitHeap(&h); 
    InitUF(); 

    InsertHeapEdge(&h,0,1,29); 
    InsertHeapEdge(&h,1,2,15); 
    InsertHeapEdge(&h,2,3,12); 
    InsertHeapEdge(&h,3,4,22); 
    InsertHeapEdge(&h,4,5,27); 
    InsertHeapEdge(&h,5,0,10); 
    InsertHeapEdge(&h,6,1,16); 
    InsertHeapEdge(&h,6,3,18); 
    InsertHeapEdge(&h,6,4,25); 

    while(edgeCount < n-1) // ������ ������ n-1�� �� �� ���� 
    { 
        e=DeleteHeap(&h); // �ּ� �� 
         
        // ���� ����ġ�� ���� ���� ������ ���� 
        uSet=SetFind(e.u);  
        vSet=SetFind(e.v); 

        if(uSet != vSet) // ������ ��ǥ ���Ұ� ���� ���� ��쿡�� 
        { 
            printf("(%d,%d) %d\n",e.u,e.v,e.key); 
            sum+=e.key; 
            edgeCount++; // ������ �ϳ� �ø��� 
            SetUnion(uSet,vSet); // �� ������ ��ģ�� 
        } 
    } 

    printf("�ּ� ����� ���� ���� %d \n\n",sum); 

    for(int m=0;m<n;m++) 
        printf("�ڽ� [%d] : �θ� %d\n",m,parent[m]); 

    return 0; 
} 

int main() 
{ 
    kruskal(7); // ���� ������ ������ 7���� �������Ҵ�. 
}