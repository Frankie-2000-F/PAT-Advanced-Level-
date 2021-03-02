import java.io.IOException;
import java.util.Scanner;

class Vertex{
    public int vertexValue;
    public boolean isVisited;
    public Vertex(int vertexValue){
        this.vertexValue = vertexValue;
        this.isVisited = false;
    }
}

class Graph{
    public int matrix[][];
    public int vertexNum;
    public Vertex vertexList[];
    public Graph(int num){
        this.vertexNum = 0;
        this.matrix = new int[num][num];
        this.vertexList = new Vertex[num];
        //Initialize the matrix
        for(int i = 0; i < num; i++){
            for(int j = 0; j < num; j++){
                if(i == j)
                    matrix[i][j] = 0;
                else
                    matrix[i][j] = Integer.MAX_VALUE;
            }
        }
    }
    public void addVertex(int value){
        vertexList[vertexNum++] = new Vertex(value);
    }
    public void addEdge(int start, int end, int value){
        matrix[start][end] = value;
        matrix[end][start] = value;
    }
}

public class Main {

    private static int MAX_VALUE=505;
    private static int INF=Integer.MAX_VALUE;
    private static int[] dist=new int[MAX_VALUE];//记录最终最短路径
    private static int[] num=new int[MAX_VALUE];//记录计算时不同的最短路径条数
    private static int[] sum=new int[MAX_VALUE];//记录救援队总数，即顶点值得和


    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(System.in);
        while(input.hasNextInt()){
            int N = input.nextInt();
            int M = input.nextInt();
            int C1 = input.nextInt();
            int C2 = input.nextInt();
            Graph city = new Graph(N);

            for(int i = 0; i < N; i++){
                city.addVertex( input.nextInt());
            }
            for(int i = 0; i < M; i++){
                city.addEdge(input.nextInt(), input.nextInt(), input.nextInt());
            }
            num[C1] = 1;
            sum[C1] = city.vertexList[C1].vertexValue;

            for(int i = 0; i < N; i++){
                dist[i] = city.matrix[C1][i];
                sum[i] = city.vertexList[i].vertexValue;
            }
            for(int i = 0; i < N-1; i++){
                int index = -1;
                int mindist = INF;
                for(int j = 0; j < N; j++) {
                    if (!city.vertexList[j].isVisited && dist[j] < mindist) {
                        mindist = dist[j];
                        index = j;
                    }
                }
                if(index == -1)
                    break;
                city.vertexList[index].isVisited = true;
                for(int j = 0; j < N; j++){
                    if(!city.vertexList[j].isVisited && city.matrix[index][j] != INF){
                        if(dist[index] + city.matrix[index][j] < dist[j]){
                            dist[j] = dist[index] + city.matrix[index][j];
                            num[j] = num[index];
                            sum[j] = sum[index] + city.vertexList[j].vertexValue;
                        }else if(dist[index] + city.matrix[index][j] == dist[j]){
                            num[j] += num[index];
                            if( sum[j] < sum[index] + city.vertexList[j].vertexValue)
                                sum[j] = sum[index] + city.vertexList[j].vertexValue;
                        }
                    }
                }
            }
            System.out.print(num[C2] + " " + sum[C2]);

        }
    }
}
