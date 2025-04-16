import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class CalculatorAWTSwing extends JFrame implements ActionListener {
    JTextField tf1, tf2;
    JTextArea resultArea;
    JButton addBtn, subBtn, mulBtn, divBtn;

    public CalculatorAWTSwing() {
        setTitle("Simple Calculator");
        setSize(350, 300);
        setLayout(null);

        // Input Fields
        tf1 = new JTextField();
        tf1.setBounds(50, 30, 100, 30);
        add(tf1);

        tf2 = new JTextField();
        tf2.setBounds(180, 30, 100, 30);
        add(tf2);

        // Result Area
        resultArea = new JTextArea();
        resultArea.setBounds(50, 160, 230, 80);
        add(resultArea);

        // Buttons
        addBtn = new JButton("+");
        subBtn = new JButton("-");
        mulBtn = new JButton("*");
        divBtn = new JButton("/");

        addBtn.setBounds(50, 80, 50, 30);
        subBtn.setBounds(110, 80, 50, 30);
        mulBtn.setBounds(170, 80, 50, 30);
        divBtn.setBounds(230, 80, 50, 30);

        add(addBtn);
        add(subBtn);
        add(mulBtn);
        add(divBtn);

        // Add Listeners
        addBtn.addActionListener(this);
        subBtn.addActionListener(this);
        mulBtn.addActionListener(this);
        divBtn.addActionListener(this);

        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        try {
            int a = Integer.parseInt(tf1.getText());
            int b = Integer.parseInt(tf2.getText());
            int result = 0;

            if (e.getSource() == addBtn) {
                result = a + b;
                resultArea.setText("Addition: " + result);
            } else if (e.getSource() == subBtn) {
                result = a - b;
                resultArea.setText("Subtraction: " + result);
            } else if (e.getSource() == mulBtn) {
                result = a * b;
                resultArea.setText("Multiplication: " + result);
            } else if (e.getSource() == divBtn) {
                if (b == 0)
                    resultArea.setText("Cannot divide by zero!");
                else
                    resultArea.setText("Division: " + (a / b));
            }
        } catch (NumberFormatException ex) {
            resultArea.setText("Please enter valid numbers.");
        }
    }

    public static void main(String[] args) {
        new CalculatorAWTSwing();
    }
}
