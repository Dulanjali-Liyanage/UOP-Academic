import javax.swing.JOptionPane;
public class MainFrame extends javax.swing.JFrame {

    int x = 0;//if x = 0 it is first player's turn. if x = 1 it is second players turn.
    int bb1 = 0,bb2 = 0,bb3 = 0,bb4 = 0,bb5 = 0,bb6 = 0,bb7 = 0,bb8 = 0,bb9 = 0;
    public MainFrame() {
        initComponents();
        jPanel1.setVisible(true);
    }
    @SuppressWarnings("unchecked")
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        b1 = new javax.swing.JButton();
        b2 = new javax.swing.JButton();
        b4 = new javax.swing.JButton();
        b6 = new javax.swing.JButton();
        b3 = new javax.swing.JButton();
        b9 = new javax.swing.JButton();
        b5 = new javax.swing.JButton();
        b7 = new javax.swing.JButton();
        b8 = new javax.swing.JButton();
        jMenuBar1 = new javax.swing.JMenuBar();
        jMenu1 = new javax.swing.JMenu();
        jMenuItem1 = new javax.swing.JMenuItem();
        jMenuItem2 = new javax.swing.JMenuItem();
        jMenu2 = new javax.swing.JMenu();
        jMenuItem3 = new javax.swing.JMenuItem();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Tick Tact Toe");

        jPanel1.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));

        b1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                b1ActionPerformed(evt);
            }
        });

        b2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                b2ActionPerformed(evt);
            }
        });

        b4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                b4ActionPerformed(evt);
            }
        });

        b6.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                b6ActionPerformed(evt);
            }
        });

        b3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                b3ActionPerformed(evt);
            }
        });

        b9.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                b9ActionPerformed(evt);
            }
        });

        b5.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                b5ActionPerformed(evt);
            }
        });

        b7.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                b7ActionPerformed(evt);
            }
        });

        b8.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                b8ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
                jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(jPanel1Layout.createSequentialGroup()
                                .addComponent(b4, javax.swing.GroupLayout.PREFERRED_SIZE, 94, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(b5, javax.swing.GroupLayout.PREFERRED_SIZE, 94, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(b6, javax.swing.GroupLayout.PREFERRED_SIZE, 94, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGroup(jPanel1Layout.createSequentialGroup()
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                        .addGroup(jPanel1Layout.createSequentialGroup()
                                                .addComponent(b1, javax.swing.GroupLayout.PREFERRED_SIZE, 94, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addComponent(b2, javax.swing.GroupLayout.PREFERRED_SIZE, 94, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addComponent(b3, javax.swing.GroupLayout.PREFERRED_SIZE, 94, javax.swing.GroupLayout.PREFERRED_SIZE))
                                        .addGroup(jPanel1Layout.createSequentialGroup()
                                                .addComponent(b7, javax.swing.GroupLayout.PREFERRED_SIZE, 94, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addComponent(b8, javax.swing.GroupLayout.PREFERRED_SIZE, 94, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addComponent(b9, javax.swing.GroupLayout.PREFERRED_SIZE, 94, javax.swing.GroupLayout.PREFERRED_SIZE)))
                                .addGap(0, 0, Short.MAX_VALUE))
        );
        jPanel1Layout.setVerticalGroup(
                jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(jPanel1Layout.createSequentialGroup()
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                        .addComponent(b3, javax.swing.GroupLayout.PREFERRED_SIZE, 80, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                                .addComponent(b1, javax.swing.GroupLayout.PREFERRED_SIZE, 80, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addComponent(b2, javax.swing.GroupLayout.PREFERRED_SIZE, 80, javax.swing.GroupLayout.PREFERRED_SIZE)))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                        .addComponent(b4, javax.swing.GroupLayout.PREFERRED_SIZE, 80, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addComponent(b6, javax.swing.GroupLayout.PREFERRED_SIZE, 80, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addComponent(b5, javax.swing.GroupLayout.PREFERRED_SIZE, 80, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                        .addComponent(b7, javax.swing.GroupLayout.PREFERRED_SIZE, 80, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addComponent(b8, javax.swing.GroupLayout.PREFERRED_SIZE, 80, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addComponent(b9, javax.swing.GroupLayout.PREFERRED_SIZE, 80, javax.swing.GroupLayout.PREFERRED_SIZE)))
        );

        jMenu1.setText("File");

        jMenuItem1.setText("New Game");
        jMenuItem1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                b1.setText("");b2.setText("");b3.setText("");b4.setText("");b5.setText("");b6.setText("");b7.setText("");b8.setText("");b9.setText("");
                x = 0;
                bb1 = 0;
                bb2 = 0;
                bb3 = 0;
                bb4 = 0;
                bb5 = 0;
                bb6 = 0;
                bb7 = 0;
                bb8 = 0;
                bb9 = 0;
                jMenuItem1ActionPerformed(evt);
            }
        });
        jMenu1.add(jMenuItem1);

        jMenuItem2.setText("Exit");
        jMenuItem2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem2ActionPerformed(evt);
            }
        });
        jMenu1.add(jMenuItem2);

        jMenuBar1.add(jMenu1);

        jMenu2.setText("About");
        jMenu2.setToolTipText("About the game and get help");
        jMenu2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenu2ActionPerformed(evt);
            }
        });

        jMenuItem3.setText("Help");
        jMenuItem3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem3ActionPerformed(evt);
            }
        });
        jMenu2.add(jMenuItem3);

        jMenuBar1.add(jMenu2);

        setJMenuBar(jMenuBar1);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(layout.createSequentialGroup()
                                .addContainerGap()
                                .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(layout.createSequentialGroup()
                                .addContainerGap()
                                .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        pack();
    }

    private void b1ActionPerformed(java.awt.event.ActionEvent evt) {
        if(x == 0) {
            if (b1.getText() == "") {
                b1.setText("1");
                x = 1;
            }

        }else{
            if(b1.getText() == "") {
                b1.setText("2");
                x = 0;
            }

        }
        bb1 = 1;
        checkwin();
    }

    private void b2ActionPerformed(java.awt.event.ActionEvent evt) {
        if(x == 0){
            if(b2.getText() == "") {
                b2.setText("1");
                x = 1;

            }
        }else{
            if(b2.getText() == "") {
                b2.setText("2");
                x = 0;
            }

        }
        bb2 = 1;
        checkwin();
    }

    private void b3ActionPerformed(java.awt.event.ActionEvent evt) {
        if(x == 0){
            if(b3.getText() == "") {
                b3.setText("1");
                x = 1;
            }
        }else{
            if(b3.getText() == "") {
                b3.setText("2");
                x = 0;
            }
        }
        bb3 = 1;
        checkwin();
    }

    private void b4ActionPerformed(java.awt.event.ActionEvent evt) {
        if(x == 0){
            if(b4.getText() == "") {
                b4.setText("1");
                x = 1;
            }
        }else{
            if(b4.getText() == "") {
                b4.setText("2");
                x = 0;
            }
        }
        bb4 = 1;
        checkwin();
    }

    private void b5ActionPerformed(java.awt.event.ActionEvent evt) {
        if(x == 0){
            if(b5.getText() == "") {
                b5.setText("1");
                x = 1;
            }
        }else{
            if(b5.getText() == "") {
                b5.setText("2");
                x = 0;
            }
        }
        bb5 = 1;
        checkwin();
    }

    private void b6ActionPerformed(java.awt.event.ActionEvent evt) {
        if(x == 0){
            if(b6.getText() == "") {
                b6.setText("1");
                x = 1;
            }
        }else{
            if(b6.getText() == "") {
                b6.setText("2");
                x = 0;
            }
        }
        bb6 = 1;
        checkwin();
    }

    private void b7ActionPerformed(java.awt.event.ActionEvent evt) {
        if(x == 0){
            if(b7.getText() == "") {
                b7.setText("1");
                x = 1;
            }
        }else{
            if(b7.getText() == "") {
                b7.setText("2");
                x = 0;
            }
        }
        bb7 = 1;
        checkwin();
    }

    private void b8ActionPerformed(java.awt.event.ActionEvent evt) {
        if(x == 0){
            if(b8.getText() == "") {
                b8.setText("1");
                x = 1;
            }
        }else{
            if(b8.getText() == "") {
                b8.setText("2");
                x = 0;
            }
        }
        bb8 = 1;
        checkwin();
    }

    private void b9ActionPerformed(java.awt.event.ActionEvent evt) {
        if(x == 0){
            if(b9.getText() == "") {
                b9.setText("1");
                x = 1;
            }
        }else{
            if(b9.getText() == "") {
                b9.setText("2");
                x = 0;
            }
        }
        bb9 = 1;
        checkwin();
    }

    private void jMenuItem1ActionPerformed(java.awt.event.ActionEvent evt) {
        jPanel1.setVisible(true);
    }

    private void jMenuItem2ActionPerformed(java.awt.event.ActionEvent evt) {
        int option = JOptionPane.showConfirmDialog(this, "Are you sure you want to Exit the game?", "Exit Game", JOptionPane.YES_NO_OPTION);

        if(option == JOptionPane.YES_NO_OPTION){
            System.exit(0);
        }
    }

    private void jMenu2ActionPerformed(java.awt.event.ActionEvent evt) {

    }

    //A simple discription msg about the game
    private void jMenuItem3ActionPerformed(java.awt.event.ActionEvent evt) {
        JOptionPane.showMessageDialog(JOptionPane.getDesktopPaneForComponent(jMenuItem3), "This game can be played by 2 players.One player indicates by 1s\n and the other indicates by 2s. A player will get only one chance at\n a time. a player wins the game when he/she will succeed in making 3 1s\n or 2s in a line. A line means that horizontally, vertically or diagonally. \nSo start the game and have fun!");
    }


    //method to check the 1 win , 2 win or draw of the game
    //if 1,2 or draw then set all the things to the initial values and start from the begining
    void checkwin(){
        if(b1.getText() == "1" & b2.getText() == "1" & b3.getText() == "1" ){
            JOptionPane.showMessageDialog(JOptionPane.getFrameForComponent(b1), "1 win!");
            b1.setText("");b2.setText("");b3.setText("");b4.setText("");b5.setText("");b6.setText("");b7.setText("");b8.setText("");b9.setText("");
            x = 0;
            bb1 = 0;
            bb2 = 0;
            bb3 = 0;
            bb4 = 0;
            bb5 = 0;
            bb6 = 0;
            bb7 = 0;
            bb8 = 0;
            bb9 = 0;
        }else{
            if(b1.getText() == "2" & b2.getText() == "2" & b3.getText() == "2" ){
                JOptionPane.showMessageDialog(JOptionPane.getFrameForComponent(b1), "2 win!");
                b1.setText("");b2.setText("");b3.setText("");b4.setText("");b5.setText("");b6.setText("");b7.setText("");b8.setText("");b9.setText("");
                x = 0;
                bb1 = 0;
                bb2 = 0;
                bb3 = 0;
                bb4 = 0;
                bb5 = 0;
                bb6 = 0;
                bb7 = 0;
                bb8 = 0;
                bb9 = 0;
            }else{
                if(b4.getText() == "1" & b5.getText() == "1" & b6.getText() == "1" ){
                    JOptionPane.showMessageDialog(JOptionPane.getFrameForComponent(b4), "1 win!");
                    b1.setText("");b2.setText("");b3.setText("");b4.setText("");b5.setText("");b6.setText("");b7.setText("");b8.setText("");b9.setText("");
                    x = 0;
                    bb1 = 0;
                    bb2 = 0;
                    bb3 = 0;
                    bb4 = 0;
                    bb5 = 0;
                    bb6 = 0;
                    bb7 = 0;
                    bb8 = 0;
                    bb9 = 0;
                }else{
                    if(b4.getText() == "2" & b5.getText() == "2" & b6.getText() == "2" ){
                        JOptionPane.showMessageDialog(JOptionPane.getFrameForComponent(b5), "2 win!");
                        b1.setText("");b2.setText("");b3.setText("");b4.setText("");b5.setText("");b6.setText("");b7.setText("");b8.setText("");b9.setText("");
                        x = 0;
                        bb1 = 0;
                        bb2 = 0;
                        bb3 = 0;
                        bb4 = 0;
                        bb5 = 0;
                        bb6 = 0;
                        bb7 = 0;
                        bb8 = 0;
                        bb9 = 0;
                    }else{
                        if(b7.getText() == "1" & b8.getText() == "1" & b9.getText() == "1" ){
                            JOptionPane.showMessageDialog(JOptionPane.getFrameForComponent(b6), "1 win!");
                            b1.setText("");b2.setText("");b3.setText("");b4.setText("");b5.setText("");b6.setText("");b7.setText("");b8.setText("");b9.setText("");
                            x = 0;
                            bb1 = 0;
                            bb2 = 0;
                            bb3 = 0;
                            bb4 = 0;
                            bb5 = 0;
                            bb6 = 0;
                            bb7 = 0;
                            bb8 = 0;
                            bb9 = 0;
                        }else{
                            if(b7.getText() == "2" & b8.getText() == "2" & b9.getText() == "2" ){
                                JOptionPane.showMessageDialog(JOptionPane.getFrameForComponent(b7), "2 win!");
                                b1.setText("");b2.setText("");b3.setText("");b4.setText("");b5.setText("");b6.setText("");b7.setText("");b8.setText("");b9.setText("");
                                x = 0;
                                bb1 = 0;
                                bb2 = 0;
                                bb3 = 0;
                                bb4 = 0;
                                bb5 = 0;
                                bb6 = 0;
                                bb7 = 0;
                                bb8 = 0;
                                bb9 = 0;
                            }else{
                                if(b1.getText() == "1" & b4.getText() == "1" & b7.getText() == "1" ){
                                    JOptionPane.showMessageDialog(JOptionPane.getFrameForComponent(b8), "1 win!");
                                    b1.setText("");b2.setText("");b3.setText("");b4.setText("");b5.setText("");b6.setText("");b7.setText("");b8.setText("");b9.setText("");
                                    x = 0;
                                    bb1 = 0;
                                    bb2 = 0;
                                    bb3 = 0;
                                    bb4 = 0;
                                    bb5 = 0;
                                    bb6 = 0;
                                    bb7 = 0;
                                    bb8 = 0;
                                    bb9 = 0;
                                }else{
                                    if(b1.getText() == "2" & b4.getText() == "2" & b7.getText() == "2" ){
                                        JOptionPane.showMessageDialog(JOptionPane.getFrameForComponent(b9), "2 win!");
                                        b1.setText("");b2.setText("");b3.setText("");b4.setText("");b5.setText("");b6.setText("");b7.setText("");b8.setText("");b9.setText("");
                                        x = 0;
                                        bb1 = 0;
                                        bb2 = 0;
                                        bb3 = 0;
                                        bb4 = 0;
                                        bb5 = 0;
                                        bb6 = 0;
                                        bb7 = 0;
                                        bb8 = 0;
                                        bb9 = 0;
                                    }else{
                                        if(b2.getText() == "1" & b5.getText() == "1" & b8.getText() == "1" ){
                                            JOptionPane.showMessageDialog(JOptionPane.getFrameForComponent(b8), "1 win!");
                                            b1.setText("");b2.setText("");b3.setText("");b4.setText("");b5.setText("");b6.setText("");b7.setText("");b8.setText("");b9.setText("");
                                            x = 0;
                                            bb1 = 0;
                                            bb2 = 0;
                                            bb3 = 0;
                                            bb4 = 0;
                                            bb5 = 0;
                                            bb6 = 0;
                                            bb7 = 0;
                                            bb8 = 0;
                                            bb9 = 0;
                                        }else{
                                            if(b2.getText() == "2" & b5.getText() == "2" & b8.getText() == "2" ){
                                                JOptionPane.showMessageDialog(JOptionPane.getFrameForComponent(b9), "2 win!");
                                                b1.setText("");b2.setText("");b3.setText("");b4.setText("");b5.setText("");b6.setText("");b7.setText("");b8.setText("");b9.setText("");
                                                x = 0;
                                                bb1 = 0;
                                                bb2 = 0;
                                                bb3 = 0;
                                                bb4 = 0;
                                                bb5 = 0;
                                                bb6 = 0;
                                                bb7 = 0;
                                                bb8 = 0;
                                                bb9 = 0;
                                            }else{
                                                if(b3.getText() == "1" & b6.getText() == "1" & b9.getText() == "1" ){
                                                    JOptionPane.showMessageDialog(JOptionPane.getFrameForComponent(b8), "1 win!");
                                                    b1.setText("");b2.setText("");b3.setText("");b4.setText("");b5.setText("");b6.setText("");b7.setText("");b8.setText("");b9.setText("");
                                                    x = 0;
                                                    bb1 = 0;
                                                    bb2 = 0;
                                                    bb3 = 0;
                                                    bb4 = 0;
                                                    bb5 = 0;
                                                    bb6 = 0;
                                                    bb7 = 0;
                                                    bb8 = 0;
                                                    bb9 = 0;
                                                }else{
                                                    if(b3.getText() == "2" & b6.getText() == "2" & b9.getText() == "2" ){
                                                        JOptionPane.showMessageDialog(JOptionPane.getFrameForComponent(b9), "2 win!");
                                                        b1.setText("");b2.setText("");b3.setText("");b4.setText("");b5.setText("");b6.setText("");b7.setText("");b8.setText("");b9.setText("");
                                                        x = 0;
                                                        bb1 = 0;
                                                        bb2 = 0;
                                                        bb3 = 0;
                                                        bb4 = 0;
                                                        bb5 = 0;
                                                        bb6 = 0;
                                                        bb7 = 0;
                                                        bb8 = 0;
                                                        bb9 = 0;
                                                    }else{
                                                        if(b1.getText() == "1" & b5.getText() == "1" & b9.getText() == "1" ){
                                                            JOptionPane.showMessageDialog(JOptionPane.getFrameForComponent(b8), "1 win!");
                                                            b1.setText("");b2.setText("");b3.setText("");b4.setText("");b5.setText("");b6.setText("");b7.setText("");b8.setText("");b9.setText("");
                                                            x = 0;
                                                            bb1 = 0;
                                                            bb2 = 0;
                                                            bb3 = 0;
                                                            bb4 = 0;
                                                            bb5 = 0;
                                                            bb6 = 0;
                                                            bb7 = 0;
                                                            bb8 = 0;
                                                            bb9 = 0;
                                                        }else{
                                                            if(b1.getText() == "2" & b5.getText() == "2" & b9.getText() == "2" ){
                                                                JOptionPane.showMessageDialog(JOptionPane.getFrameForComponent(b9), "2 win!");
                                                                b1.setText("");b2.setText("");b3.setText("");b4.setText("");b5.setText("");b6.setText("");b7.setText("");b8.setText("");b9.setText("");
                                                                x = 0;
                                                                bb1 = 0;
                                                                bb2 = 0;
                                                                bb3 = 0;
                                                                bb4 = 0;
                                                                bb5 = 0;
                                                                bb6 = 0;
                                                                bb7 = 0;
                                                                bb8 = 0;
                                                                bb9 = 0;
                                                            }else{
                                                                if(b3.getText() == "1" & b5.getText() == "1" & b7.getText() == "1" ){
                                                                    JOptionPane.showMessageDialog(JOptionPane.getFrameForComponent(b8), "1 win!");
                                                                    b1.setText("");b2.setText("");b3.setText("");b4.setText("");b5.setText("");b6.setText("");b7.setText("");b8.setText("");b9.setText("");
                                                                    x = 0;
                                                                    bb1 = 0;
                                                                    bb2 = 0;
                                                                    bb3 = 0;
                                                                    bb4 = 0;
                                                                    bb5 = 0;
                                                                    bb6 = 0;
                                                                    bb7 = 0;
                                                                    bb8 = 0;
                                                                    bb9 = 0;
                                                                }else{
                                                                    if(b3.getText() == "2" & b5.getText() == "2" & b7.getText() == "2" ){
                                                                        JOptionPane.showMessageDialog(JOptionPane.getFrameForComponent(b9), "2 win!");
                                                                        b1.setText("");b2.setText("");b3.setText("");b4.setText("");b5.setText("");b6.setText("");b7.setText("");b8.setText("");b9.setText("");
                                                                        x = 0;
                                                                        bb1 = 0;
                                                                        bb2 = 0;
                                                                        bb3 = 0;
                                                                        bb4 = 0;
                                                                        bb5 = 0;
                                                                        bb6 = 0;
                                                                        bb7 = 0;
                                                                        bb8 = 0;
                                                                        bb9 = 0;
                                                                    }
                                                                    else{
                                                                        if(bb1 == 1 & bb2 == 1 & bb3 == 1 & bb4 == 1 & bb5 == 1 & bb6 == 1 & bb7 == 1 & bb8 == 1 & bb9 == 1){
                                                                            JOptionPane.showMessageDialog(JOptionPane.getFrameForComponent(b9), "Draw!");
                                                                            b1.setText("");b2.setText("");b3.setText("");b4.setText("");b5.setText("");b6.setText("");b7.setText("");b8.setText("");b9.setText("");
                                                                            x = 0;
                                                                            bb1 = 0;
                                                                            bb2 = 0;
                                                                            bb3 = 0;
                                                                            bb4 = 0;
                                                                            bb5 = 0;
                                                                            bb6 = 0;
                                                                            bb7 = 0;
                                                                            bb8 = 0;
                                                                            bb9 = 0;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    public static void main(String args[]) {

        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(MainFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(MainFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(MainFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(MainFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }


        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {

                new MainFrame().setVisible(true);
            }
        });
    }

    // Variables declaration
    private javax.swing.JButton b1;
    private javax.swing.JButton b2;
    private javax.swing.JButton b3;
    private javax.swing.JButton b4;
    private javax.swing.JButton b5;
    private javax.swing.JButton b6;
    private javax.swing.JButton b7;
    private javax.swing.JButton b8;
    private javax.swing.JButton b9;
    private javax.swing.JMenu jMenu1;
    private javax.swing.JMenu jMenu2;
    private javax.swing.JMenuBar jMenuBar1;
    private javax.swing.JMenuItem jMenuItem1;
    private javax.swing.JMenuItem jMenuItem2;
    private javax.swing.JMenuItem jMenuItem3;
    private javax.swing.JPanel jPanel1;
    // End of variables declaration
}
