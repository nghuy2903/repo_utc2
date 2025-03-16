namespace WinFormsAppB4
{
    partial class Form4
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
            ListViewItem listViewItem1 = new ListViewItem(new string[] { "01", "Tong China", "15000" }, -1);
            ListViewItem listViewItem2 = new ListViewItem(new string[] { "02", "Sữa Bà Cụ", "7000000" }, -1);
            listView1 = new ListView();
            Id_Product = new ColumnHeader();
            Name_Product = new ColumnHeader();
            Price_Product = new ColumnHeader();
            lblId = new Label();
            txtId = new TextBox();
            txtName = new TextBox();
            lblName = new Label();
            txtPrice = new TextBox();
            lblPrice = new Label();
            btnAdd = new Button();
            btnRemove = new Button();
            btnRemoveAll = new Button();
            btnUpdate = new Button();
            contextMenuStrip1 = new ContextMenuStrip(components);
            editToolStripMenuItem = new ToolStripMenuItem();
            removeToolStripMenuItem = new ToolStripMenuItem();
            contextMenuStrip1.SuspendLayout();
            SuspendLayout();
            // 
            // listView1
            // 
            listView1.Columns.AddRange(new ColumnHeader[] { Id_Product, Name_Product, Price_Product });
            listView1.FullRowSelect = true;
            listView1.GridLines = true;
            listView1.HoverSelection = true;
            listView1.Items.AddRange(new ListViewItem[] { listViewItem1, listViewItem2 });
            listView1.Location = new Point(91, 232);
            listView1.Name = "listView1";
            listView1.Size = new Size(524, 164);
            listView1.TabIndex = 0;
            listView1.UseCompatibleStateImageBehavior = false;
            listView1.View = View.Details;
            listView1.SelectedIndexChanged += listView1_SelectedIndexChanged;
            listView1.MouseClick += listView1_MouseClick;
            // 
            // Id_Product
            // 
            Id_Product.Text = "Id_Product";
            Id_Product.Width = 100;
            // 
            // Name_Product
            // 
            Name_Product.Text = "Name_Product";
            Name_Product.Width = 150;
            // 
            // Price_Product
            // 
            Price_Product.Text = "Price_Product";
            Price_Product.Width = 150;
            // 
            // lblId
            // 
            lblId.AutoSize = true;
            lblId.Location = new Point(106, 54);
            lblId.Name = "lblId";
            lblId.Size = new Size(79, 20);
            lblId.TabIndex = 1;
            lblId.Text = "Id_Product";
            // 
            // txtId
            // 
            txtId.Location = new Point(264, 47);
            txtId.Name = "txtId";
            txtId.Size = new Size(292, 27);
            txtId.TabIndex = 2;
            // 
            // txtName
            // 
            txtName.Location = new Point(264, 96);
            txtName.Name = "txtName";
            txtName.Size = new Size(292, 27);
            txtName.TabIndex = 4;
            // 
            // lblName
            // 
            lblName.AutoSize = true;
            lblName.Location = new Point(106, 103);
            lblName.Name = "lblName";
            lblName.Size = new Size(106, 20);
            lblName.TabIndex = 3;
            lblName.Text = "Name_Product";
            // 
            // txtPrice
            // 
            txtPrice.Location = new Point(264, 153);
            txtPrice.Name = "txtPrice";
            txtPrice.Size = new Size(292, 27);
            txtPrice.TabIndex = 6;
            // 
            // lblPrice
            // 
            lblPrice.AutoSize = true;
            lblPrice.Location = new Point(106, 160);
            lblPrice.Name = "lblPrice";
            lblPrice.Size = new Size(98, 20);
            lblPrice.TabIndex = 5;
            lblPrice.Text = "Price_Product";
            // 
            // btnAdd
            // 
            btnAdd.Location = new Point(631, 26);
            btnAdd.Name = "btnAdd";
            btnAdd.Size = new Size(115, 29);
            btnAdd.TabIndex = 7;
            btnAdd.Text = "Add";
            btnAdd.UseVisualStyleBackColor = true;
            btnAdd.Click += btnAdd_Click;
            // 
            // btnRemove
            // 
            btnRemove.Location = new Point(631, 74);
            btnRemove.Name = "btnRemove";
            btnRemove.Size = new Size(115, 29);
            btnRemove.TabIndex = 8;
            btnRemove.Text = "RemoveAt";
            btnRemove.UseVisualStyleBackColor = true;
            btnRemove.Click += btnRemove_Click;
            // 
            // btnRemoveAll
            // 
            btnRemoveAll.Location = new Point(631, 124);
            btnRemoveAll.Name = "btnRemoveAll";
            btnRemoveAll.Size = new Size(115, 29);
            btnRemoveAll.TabIndex = 9;
            btnRemoveAll.Text = "RemoveAll";
            btnRemoveAll.UseVisualStyleBackColor = true;
            btnRemoveAll.Click += btnRemoveAll_Click;
            // 
            // btnUpdate
            // 
            btnUpdate.Location = new Point(631, 171);
            btnUpdate.Name = "btnUpdate";
            btnUpdate.Size = new Size(115, 29);
            btnUpdate.TabIndex = 10;
            btnUpdate.Text = "Update";
            btnUpdate.UseVisualStyleBackColor = true;
            btnUpdate.Click += btnUpdate_Click;
            // 
            // contextMenuStrip1
            // 
            contextMenuStrip1.ImageScalingSize = new Size(20, 20);
            contextMenuStrip1.Items.AddRange(new ToolStripItem[] { editToolStripMenuItem, removeToolStripMenuItem });
            contextMenuStrip1.Name = "contextMenuStrip1";
            contextMenuStrip1.Size = new Size(137, 56);
            // 
            // editToolStripMenuItem
            // 
            editToolStripMenuItem.Image = Properties.Resources.pencil;
            editToolStripMenuItem.Name = "editToolStripMenuItem";
            editToolStripMenuItem.Size = new Size(136, 26);
            editToolStripMenuItem.Text = "Edit";
            editToolStripMenuItem.Click += editToolStripMenuItem_Click;
            // 
            // removeToolStripMenuItem
            // 
            removeToolStripMenuItem.Image = Properties.Resources.tải_xuống;
            removeToolStripMenuItem.Name = "removeToolStripMenuItem";
            removeToolStripMenuItem.Size = new Size(136, 26);
            removeToolStripMenuItem.Text = "Remove";
            removeToolStripMenuItem.Click += removeToolStripMenuItem_Click;
            // 
            // Form4
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(btnUpdate);
            Controls.Add(btnRemoveAll);
            Controls.Add(btnRemove);
            Controls.Add(btnAdd);
            Controls.Add(txtPrice);
            Controls.Add(lblPrice);
            Controls.Add(txtName);
            Controls.Add(lblName);
            Controls.Add(txtId);
            Controls.Add(lblId);
            Controls.Add(listView1);
            Name = "Form4";
            Text = "Form4";
            Load += Form4_Load;
            contextMenuStrip1.ResumeLayout(false);
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private ListView listView1;
        private ColumnHeader Id_Product;
        private ColumnHeader Name_Product;
        private ColumnHeader Price_Product;
        private Label lblId;
        private TextBox txtId;
        private TextBox txtName;
        private Label lblName;
        private TextBox txtPrice;
        private Label lblPrice;
        private Button btnAdd;
        private Button btnRemove;
        private Button btnRemoveAll;
        private Button btnUpdate;
        private ContextMenuStrip contextMenuStrip1;
        private ToolStripMenuItem editToolStripMenuItem;
        private ToolStripMenuItem removeToolStripMenuItem;
    }
}