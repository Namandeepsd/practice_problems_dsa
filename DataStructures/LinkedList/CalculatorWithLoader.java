import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class CalculatorWithLoader {

    public static void main(String[] args) {
        // Show loader splash first
        showLoader();
    }

    private static void showLoader() {
        JWindow loader = new JWindow();
        JLabel label = new JLabel("Running...", SwingConstants.CENTER);
        label.setFont(new Font("Arial", Font.BOLD, 28));
        label.setForeground(Color.WHITE);
        loader.getContentPane().setBackground(new Color(50, 150, 250));
        loader.getContentPane().add(label, BorderLayout.CENTER);
        loader.setSize(300, 150);
        loader.setLocationRelativeTo(null);
        loader.setVisible(true);

        // Delay for 2 seconds then show calculator
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        loader.setVisible(false);
        loader.dispose();

        SwingUtilities.invokeLater(Calculator::new);
    }
}

class Calculator extends JFrame implements ActionListener {

    private JTextField display;
    private StringBuilder input;
    private double num1, num2, result;
    private char operator;

    public Calculator() {
        input = new StringBuilder();

        // Window setup
        setTitle("Java Calculator");
        setSize(350, 450);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());
        setLocationRelativeTo(null);

        // Display field
        display = new JTextField();
        display.setEditable(false);
        display.setFont(new Font("Arial", Font.BOLD, 24));
        add(display, BorderLayout.NORTH);

        // Button panel
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(4, 4, 10, 10));

        String[] buttons = {
                "7", "8", "9", "/",
                "4", "5", "6", "*",
                "1", "2", "3", "-",
                "0", "C", "=", "+"
        };

        for (String text : buttons) {
            JButton btn = new JButton(text);
            btn.setFont(new Font("Arial", Font.BOLD, 20));
            btn.addActionListener(this);
            panel.add(btn);
        }

        add(panel, BorderLayout.CENTER);
        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String command = e.getActionCommand();

        if (Character.isDigit(command.charAt(0))) {
            input.append(command);
            display.setText(input.toString());
        } else if (command.equals("C")) {
            input.setLength(0);
            display.setText("");
            num1 = num2 = result = 0;
        } else if (command.equals("=")) {
            try {
                num2 = Double.parseDouble(input.toString());
                switch (operator) {
                    case '+': result = num1 + num2; break;
                    case '-': result = num1 - num2; break;
                    case '*': result = num1 * num2; break;
                    case '/': result = num2 != 0 ? num1 / num2 : 0; break;
                }
                display.setText(String.valueOf(result));
                input.setLength(0);
                input.append(result);
            } catch (Exception ex) {
                display.setText("Error");
            }
        } else {
            try {
                num1 = Double.parseDouble(input.toString());
                operator = command.charAt(0);
                input.setLength(0);
            } catch (Exception ex) {
                display.setText("Error");
            }
        }
    }
}
