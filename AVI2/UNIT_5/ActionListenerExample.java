import javax.swing.*;
import java.awt.event.*;

public class ActionListenerExample {
    public static void main(String[] args) {
        JFrame f = new JFrame("ActionListener");
        JButton b = new JButton("Click");
        JLabel l = new JLabel();
        b.setBounds(100, 50, 80, 30);
        l.setBounds(100, 100, 200, 30);
        b.addActionListener(e -> l.setText("Button Clicked"));
        f.add(b); f.add(l);
        f.setSize(300, 200);
        f.setLayout(null);
        f.setVisible(true);
    }
}
