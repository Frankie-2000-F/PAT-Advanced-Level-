    import java.util.*;



    class student{
        String ID;
        int[] scores =  new int[4];
        String bestOb;
        int bestRank = Integer.MAX_VALUE;
        int[] ranks = new int[4];
        student(String ID, int C, int M, int E){
            int A = (int)((C + M + E) / 3);
            this.scores[0] = A;
            this.scores[1] = C;
            this.scores[2] = M;
            this.scores[3] = E;
            this.ID = ID;
        }

    }

    class bestOb{
        String name;
        int rank;
        bestOb(String name, int rank){
            this.name = name;
            this.rank = rank;
        }
    }

    class myComarator implements Comparator<student>{
        int flag;
        myComarator(int flag){
            this.flag = flag;
        }
        @Override
        public int compare(student o1, student o2) {
            if(o1.scores[flag] > o2.scores[flag])
                return -1;
            else if(o1.scores[flag] < o2.scores[flag])
                return 1;
            else
                return 0;
        }
    }

    public class Main {

        public static void main(String[] args){
            Scanner input = new Scanner(System.in);
            int N = input.nextInt();
            int K = input.nextInt();
            student[] students = new student[N];
            String[] obs = {"A", "C", "M", "E"};

            for(int i = 0; i < N; i++){
                String ID = input.next();
                int C = input.nextInt();
                int M = input.nextInt();
                int E = input.nextInt();
                students[i] = new student(ID, C, M, E);
            }
            for(int i = 0; i < 4; i++) {
                Arrays.sort(students, new myComarator(i));
                students[0].ranks[i] = 1;
                students[0].bestRank = 1;
                students[0].bestOb = obs[i];
                for(int j = 1; j < N; j++){
                    if(students[j].scores[i] == students[j - 1].scores[i]){
                        students[j].ranks[i] = students[j - 1].ranks[i];
                    }else
                        students[j].ranks[i] = j + 1;

                    if(students[j].ranks[i] < students[j].bestRank){
                        students[j].bestRank = students[j].ranks[i];
                        students[j].bestOb = obs[i];
                    }
                }
            }
            HashMap<String, bestOb> mapBest = new HashMap<>();

            for(int i = 0; i < N; i++){
                mapBest.put(students[i].ID, new bestOb(students[i].bestOb, students[i].bestRank));
            }

            for(int i =0; i < K; i++){
                String id = input.next();
                if(mapBest.containsKey(id))
                        System.out.println(mapBest.get(id).rank + " " + mapBest.get(id).name);
                else
                    System.out.println("N/A");
            }

        }
    }
