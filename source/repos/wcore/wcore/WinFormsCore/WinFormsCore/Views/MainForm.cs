using System.Windows.Forms;
using WinFormsCore.Models.Entities;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace WinFormsCore.Views
{
    public partial class MainForm : Form
    {
        private readonly ShopContext _context;
        private int currentPage = 1;
        private int pageSize = 10;

        public MainForm(ShopContext context)
        {
            InitializeComponent();
            _context = context;
            var filterCustomers = _context.Customers.Where(t => t.FirstName == "Maria").ToList();
            //int a = 3;
            InitializeComboBox();
            InitiallizeListView();
        }
        private void InitializeComboBox()
        {
            cbbloadNumRow.Items.Clear();
            for(int i = 10; i<=100; i+=10)
            {
                cbbloadNumRow.Items.Add(i.ToString());
            }
            cbbloadNumRow.SelectedIndex = 0;
        }

        private void InitiallizeListView()
        {
            lvLoadData.View = View.Details;
            lvLoadData.FullRowSelect = true;

            lvLoadData.Columns.Add("STT", 50);
            lvLoadData.Columns.Add("Họ", 75);
            lvLoadData.Columns.Add("Tên", 75);
            lvLoadData.Columns.Add("Tỉnh/Tp", 100);
            lvLoadData.Columns.Add("Quốc gia", 100);
            lvLoadData.Columns.Add("Điện thoại", 100);
        } 
        private void lvLoadData_SelectedIndexChanged(object sender, EventArgs e)
        {
            var customers = _context.Customers.ToList();

            foreach (var customer in customers)
            {
                var item = new ListViewItem(customer.Id.ToString());
                item.SubItems.Add(customer.FirstName);
                item.SubItems.Add(customer.LastName);
                item.SubItems.Add(customer.City);
                item.SubItems.Add(customer.Country);
                item.SubItems.Add(customer.Phone);

                lvLoadData.Items.Add(item);
            }
        }

        private void cbbloadNumRow_SelectedIndexChanged(object sender, EventArgs e)
        {
            pageSize = int.Parse(cbbloadNumRow.SelectedItem.ToString());
            currentPage = 1;
            LoadCustomer();

        }

       

        private void UpdatePageButton()
        {
            if (currentPage > 1) btnPreviousPage.Enabled = true;
            else btnPreviousPage.Enabled = false;

            if (currentPage < 10) btnNextPage.Enabled = true;
            else btnNextPage.Enabled = false;

        }

        private void btnPreviousPage_Click(object sender, EventArgs e)
        {
            if (currentPage > 1)
            {
                currentPage--;
                LoadCustomer();
            }
        }
        private void btnNextPage_Click(object sender, EventArgs e)
        {
            if(currentPage < 10)
            {
                currentPage++;
                LoadCustomer();
            }
        }

        private void LoadCustomer()
        {

        }

        
    }
}
