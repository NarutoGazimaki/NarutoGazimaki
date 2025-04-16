import javax.swing.*;

public class SimpleSwing {
    public static void main(String[] args) {
        JFrame f = new JFrame("Swing Example");
        JLabel l = new JLabel("Hello Swing!");
        l.setBounds(100, 50, 100, 30);
        f.add(l);
        f.setSize(300, 200);
        f.setLayout(null);
        f.setVisible(true);
    }
}
