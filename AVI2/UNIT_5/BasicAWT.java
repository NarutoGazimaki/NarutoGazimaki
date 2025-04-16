import java.awt.*;

public class BasicAWT {
    public static void main(String[] args) {
        Frame f = new Frame("AWT Example");
        Label l = new Label("Hello AWT");
        l.setBounds(100, 100, 100, 30);
        f.add(l);
        f.setSize(300, 200);
        f.setLayout(null);
        f.setVisible(true);
    }
}
