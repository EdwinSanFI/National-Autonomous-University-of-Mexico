import javax.sql.XAConnection;

public class TernaryEx{
    public static void main(String[] args) {
        boolean A = true;
        boolean B = false;
        boolean C = true;   
                        //   t and t
                        //     t    or (t)and t
        System.out.println(((A|B)&A)|((A^B)&(A|B)));
        //                  f  or  
        System.out.println((A^C)^(A^B));
    }
}