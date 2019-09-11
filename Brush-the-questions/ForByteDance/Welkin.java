import java.util.*;

/**
 * @Author: liuhaoeric
 * Create time: 2019/09/03
 * Description:
 */
public class Welkin {
    private List<String> list = new ArrayList<>();
    private char[] area = new char[]{'A', 'B', 'C', 'D'};

    private Object lock = new Object();

    public void init() {

        int aIdx = 1;
        int no = 0;
        int last = 0;
        for (char a : area) {
            for (int i = 50; i <= 100; i = i + 2) {
                for (int j = 0; j <= i; j++) {
                    list.add(a + "-" + no + "-" + j);
                }
                last = i;
                no++;
            }
            aIdx++;
        }
        System.out.println(list);
    }

    public Set<String> buy(int no) {
        Set<String> ret = new HashSet<>();
        synchronized (lock) {
            for (int i = 0; i < no; i++) {
                int seat = Math.abs(new Random().nextInt() % list.size());
                System.out.println(list.get(seat));
                ret.add(list.get(seat));
                list.remove(seat);
            }
        }
        return ret;
    }

    public static void main(String[] args) {
        Welkin w = new Welkin();
        w.init();
        System.out.println(w.buy(5));
    }
}