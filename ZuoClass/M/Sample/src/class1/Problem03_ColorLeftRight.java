package class1;
import java.util.Arrays;


public class Problem03_ColorLeftRight {

    public static int minPaint(String s) {
        if (s == null || s.length() < 2) {
            return 0;
        }

        char[] chs = s.toCharArray();
        int[] right = new int[chs.length];

        right[chs.length - 1] = chs[chs.length - 1] == 'R' ? 1 : 0;
        System.out.println("16:"+Arrays.toString(right));
        System.out.println("17:"+ chs.length);
        for (int i = chs.length - 2; i >= 0; i--) {
            right[i] = right[i + 1] + (chs[i] == 'R' ? 1 : 0);
        }
        System.out.println("20:"+Arrays.toString(right));

        int res = right[0];//最左 也就是 取得R的最大值
        int left = 0;
        for (int i = 0; i < chs.length - 1; i++) {
            left += chs[i] == 'G' ? 1 : 0;//取得G的最大值? 错的 应该是遍历left值
            System.out.println("27 left :"+left);
            System.out.println("28 res :"+res);
            System.out.println("29 和 :"+(left + right[i + 1]));
            res = Math.min(res, left + right[i + 1]);
            System.out.println("31 res 比较之后 :"+res);
        }
        System.out.println("33 res 比较值钱 :"+res);
        res = Math.min(res, left + (chs[chs.length - 1] == 'G' ? 1 : 0));
        System.out.println("35 res 最终结果 :"+res);
        System.out.println("36 chs[chs.length - 1] 最终结果 :"+chs[chs.length - 1]);
        System.out.println("chs:"+Arrays.toString(chs));
        return res;
    }

    public static void main(String[] args) {
        String test = "GGRGGR";
        System.out.println("result:"+minPaint(test));

    }
}
