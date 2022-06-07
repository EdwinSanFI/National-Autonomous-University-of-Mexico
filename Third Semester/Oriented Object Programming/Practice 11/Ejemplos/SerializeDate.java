import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.util.Date;

public class SerializeDate {
    SerializeDate () {
        Date date = new Date();
        System.out.println(date);
        try {
            FileOutputStream f = new FileOutputStream("date.set");
            ObjectOutputStream s = new ObjectOutputStream(f);
            s.writeObject(date);
            s.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public static void main(String[] args) {
        new SerializeDate();
    }
}
