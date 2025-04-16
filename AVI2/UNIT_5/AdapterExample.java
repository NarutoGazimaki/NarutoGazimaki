import javax.swing.*;
import java.awt.event.*;

public class AdapterExample extends MouseAdapter {
    JFrame f;
    JLabel l;

    AdapterExample() {
        f = new JFrame("Adapter Example");
        l = new JLabel("Click inside frame");
        l.setBounds(100, 80, 200, 30);
        f.add(l);
        f.addMouseListener(this);
        f.setSize(300, 200);
        f.setLayout(null);
        f.setVisible(true);
    }

    public void mouseClicked(MouseEvent e) {
        l.setText("Clicked!");
    }

    public static void main(String[] args) {
        new AdapterExample();
    }
}
