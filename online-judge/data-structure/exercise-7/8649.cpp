#include <cstdio>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct edge_node {
    int to;
    int next;
};

int main() {
    int graph_kind;
    int vertex_num, edge_num;

    scanf("%d", &graph_kind);
    scanf("%d %d", &vertex_num, &edge_num);

    vector<string> vertex(vertex_num);
    vector<char> input_buf(16);

    for (int i = 0; i < vertex_num; i++) {
        scanf("%15s", input_buf.data());
        vertex[i] = input_buf.data();
    }

    vector<int> head(vertex_num, -1);
    vector<edge_node> edges;

    for (int i = 0; i < edge_num; i++) {
        vector<char> tail_buf(16), head_buf(16);
        scanf("%15s %15s", tail_buf.data(), head_buf.data());

        int tail_index = -1;
        int head_index = -1;

        for (int j = 0; j < vertex_num; j++) {
            if (vertex[j] == tail_buf.data()) {
                tail_index = j;
            }
            if (vertex[j] == head_buf.data()) {
                head_index = j;
            }
        }

        if (graph_kind == 1 || graph_kind == 3) {
            int weight;
            scanf("%d", &weight);
        }

        edge_node edge;
        edge.to = head_index;
        edge.next = head[tail_index];
        edges.push_back(edge);
        head[tail_index] = (int) edges.size() - 1;

        if (graph_kind == 2 || graph_kind == 3) {
            edge_node reverse_edge;
            reverse_edge.to = tail_index;
            reverse_edge.next = head[head_index];
            edges.push_back(reverse_edge);
            head[head_index] = (int) edges.size() - 1;
        }
    }

    vector<int> visited(vertex_num, 0);
    queue<int> que;
    int first_output = 1;

    for (int i = 0; i < vertex_num; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            que.push(i);

            while (!que.empty()) {
                int current = que.front();
                que.pop();

                if (!first_output) {
                    printf(" ");
                }
                printf("%s", vertex[current].c_str());
                first_output = 0;

                for (int p = head[current]; p != -1; p = edges[p].next) {
                    int next_vertex = edges[p].to;
                    if (!visited[next_vertex]) {
                        visited[next_vertex] = 1;
                        que.push(next_vertex);
                    }
                }
            }
        }
    }

    return 0;
}

/*
8649 图的广度遍历
时间限制:1000MS  代码长度限制:10KB
提交次数:1573 通过次数:975

题型: 编程题   语言: G++;GCC

Description
使用图的深度遍历实现的邻接表存储结构和基本操作函数，在此基础上实现图的广度遍历算法并加以测试。注意正确使用队列存储结构。



输入格式
第一行：输入0到3之间整数(有向图:0,有向网:1,无向图:2,无向网:3)；
第二行：输入顶点数和边数；
第三行：输入各个顶点的值（字符型，长度〈3）；(遍历从输入的第一个顶点开始)
第四行：输入每条弧(边)弧尾和弧头(以空格作为间隔),如果是网还要输入权值；


输出格式
输出对图广度遍历的结果


输入样例
0
3 3
a b c
a b
b c
c b


输出样例
a b c


提示
注意题目的邻接表采用头插法，也就是后出现的边节点插入到邻接表的表头。

*/
