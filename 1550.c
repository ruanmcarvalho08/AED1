#include <stdio.h>
#include <string.h>

int queue[1000000], dist[1000000];
int vis[1000000];

int reverse(int x){
    int r = 0;
    while(x){
        r = r*10 + (x%10);
        x /= 10;
    }
    return r;
}

int bfs(int A, int B){
    memset(vis, 0, sizeof(vis));
    int front = 0, back = 0;
    queue[back] = A;
    dist[A] = 0;
    vis[A] = 1;

    while(front <= back){
        int u = queue[front++];
        if(u == B) return dist[u];

        int v1 = u + 1;
        int v2 = reverse(u);

        if(v1 <= 100000 && !vis[v1]){
            vis[v1] = 1;
            dist[v1] = dist[u] + 1;
            queue[++back] = v1;
        }

        if(v2 <= 100000 && !vis[v2]){
            vis[v2] = 1;
            dist[v2] = dist[u] + 1;
            queue[++back] = v2;
        }
    }
    return -1;
}

int main(){
    int t, A, B;
    scanf("%d", &t);

    while(t--){
        scanf("%d %d", &A, &B);
        printf("%d\n", bfs(A, B));
    }
    return 0;
}