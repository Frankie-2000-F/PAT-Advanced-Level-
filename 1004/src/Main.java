import java.io.IOException;
import java.util.Scanner;

class Node{
    int level=0;
    int parent;
    boolean hasChild;
}

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int M = input.nextInt();
        Node[] nodes = new Node[N+1];
        for(int i = 1; i <= N; i++){
            nodes[i] = new Node();
        }
        //输入非叶子节点，记录是否有子节点和父节点序号
        for(int i = 0; i < M; i++){
            int parent = Integer.parseInt(input.next());
//            System.out.print(parent);
            nodes[parent].hasChild = true;
            int childNum = input.nextInt();
            for(int j = 0; j < childNum; j++){
                int child = Integer.parseInt(input.next());
//                System.out.print(child);
                nodes[child].parent = parent;
            }
        }
        int maxLevel = 0;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(nodes[j].parent == i){
                    nodes[j].level = nodes[i].level+1;
                    if(nodes[j].level > maxLevel)
                        maxLevel = nodes[j].level;
                }
            }
        }
//        System.out.println(maxLevel);
        int[] count = new int[maxLevel+1];
        for(int i =1; i <= N; i++){
            if(!nodes[i].hasChild)
                count[nodes[i].level]++;
        }
        for(int i = 0; i < maxLevel+1; i++){
            if(i == 0)
                System.out.print(count[0]);
            else
                System.out.print(" " + count[i]);
        }

    }
}
