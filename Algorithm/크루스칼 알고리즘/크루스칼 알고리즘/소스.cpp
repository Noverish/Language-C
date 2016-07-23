#include <stdio.h> 

#define MAX_VERTEX 100 
#define MAX_ELEMENT 100 

int parent[MAX_VERTEX]; 
int num[MAX_VERTEX]; 

typedef struct { 
    int v; // 정점1 
    int u; // 정점2 
    int key; // 간선의 가중치 
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

    while(i != 1 && item.key < h->heap[i/2].key) // 부모노드와 비교 
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
    temp = h->heap[(h->heap_size)--]; // 삭제에 의한 size 감소 

    while(child <= h->heap_size) 
    { 
         //자식 노드간 작은 수 비교  
        if((child < h->heap_size) && (h->heap[child].key) > h->heap[child+1].key)  
            child++; 
         
        if(temp.key <= h->heap[child].key) break; 

        h->heap[parent] = h->heap[child]; 
        parent = child; 
        child *= 2; // 다음 자식 노드와 비교 
    } 

    h->heap[parent]=temp; 
    return data; 
} 

void InitUF(void) // 전역 변수 초기화 
{ 
    int i; 
    for(i=0;i<MAX_VERTEX;i++) 
    { 
        parent[i]=-1; 
        num[i]=1; 
    } 
} 

int SetFind(int v) // v가 속하는 집합을 반환한다 
{ 
    int i,p,temp; 

    for(i=v;(p=parent[i])>=0;i=p); // 정점v의 루트를 찾는다 
     
    temp=i; // 정점 v를 포함하는 집합의 대표 원소  
      
    for(i=v;(p=parent[i])>=0;i=p)  
        parent[i]=temp; // 집합의 모든 원소들의 부모를 s로 설정 

    return temp; 
} 

void SetUnion(int v1,int v2) // 두개의 원소가 속한 집합을 합친다 
{ 
    if(num[v1] < num[v2]) // 자식의 갯수로 비교 
    { 
        parent[v1]=v2; // 부모 변경 
        num[v1]+=num[v2]; 
    } 
    else 
    { 
        parent[v2]=v1; // 부모 변경 
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

    while(edgeCount < n-1) // 간선의 갯수가 n-1이 될 때 까지 
    { 
        e=DeleteHeap(&h); // 최소 힙 
         
        // 가장 가중치가 가장 낮은 간선을 선택 
        uSet=SetFind(e.u);  
        vSet=SetFind(e.v); 

        if(uSet != vSet) // 서로의 대표 원소가 같지 않은 경우에만 
        { 
            printf("(%d,%d) %d\n",e.u,e.v,e.key); 
            sum+=e.key; 
            edgeCount++; // 간선을 하나 늘린다 
            SetUnion(uSet,vSet); // 두 집합을 합친다 
        } 
    } 

    printf("최소 비용의 간선 길이 %d \n\n",sum); 

    for(int m=0;m<n;m++) 
        printf("자식 [%d] : 부모 %d\n",m,parent[m]); 

    return 0; 
} 

int main() 
{ 
    kruskal(7); // 현재 간선의 갯수는 7개로 만들어놓았다. 
}