
import java.awt.*;
import javax.swing.Timer; //for timer

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.*;

public class ClientGUI
        extends JPanel implements ActionListener {
    JTextArea textArea1;
    VisualServer clientServer;

    public ClientGUI(VisualServer clientServer) {
        super(new GridBagLayout());

        textArea1 = new JTextArea(5, 20);
        textArea1.setEditable(false);
        JScrollPane scrollPane1 = new JScrollPane(textArea1);

        //Add Components to this panel.
        GridBagConstraints c1 = new GridBagConstraints();
        c1.gridwidth = GridBagConstraints.REMAINDER;

        c1.fill = GridBagConstraints.HORIZONTAL;

        c1.fill = GridBagConstraints.BOTH;
        c1.weightx = 1.0;
        c1.weighty = 1.0;
        add(scrollPane1, c1);

        Timer timer1 = new Timer(500, this);
        timer1.start();

        this.clientServer = clientServer;
    }

    public void actionPerformed(ActionEvent e) {
        String newline1 = clientServer.getMSGClient();
        if(newline1 != null) {
            textArea1.append(newline1 + "\n");

            //Make sure the new text is visible, even if there
            //was a selection in the text area.
            textArea1.setCaretPosition(textArea1.getDocument().getLength());
        }

    }
}
