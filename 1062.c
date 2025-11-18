int main() {
    int n, i;
    int target[1005];
    int stack[1005];
    int top;

    while (scanf("%d", &n) && n != 0) {
        while (1) {
            scanf("%d", &target[0]);
            if (target[0] == 0) {
                printf("\n");
                break;
            }
            
            for (i = 1; i < n; i++) {
                scanf("%d", &target[i]);
            }

            top = 0;
            int current_in = 1;
            int target_idx = 0;

            while (current_in <= n) {
                stack[top] = current_in;
                top++;
                current_in++;

                while (top > 0 && stack[top-1] == target[target_idx]) {
                    top--;
                    target_idx++;
                }
            }

            if (top == 0) 
                printf("Yes\n");
            else 
                printf("No\n");
        }
    }
    return 0;
}