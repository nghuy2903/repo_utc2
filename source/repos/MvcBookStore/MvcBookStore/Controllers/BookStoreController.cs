using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using MvcBookStore.Models;

namespace MvcBookStore.Controllers
{
    public class BookStoreController : Controller
    {
        private readonly QLBanSachEntities2 db;
        
        public BookStoreController()
        {
            db = new QLBanSachEntities2();
        }
        // GET: BookStore

        private List<SACH> LaySachMoi(int count)
        {
            return db.SACH.OrderBy(a=>a.Ngaycapnhat).Take(count).ToList(); 
        }
        public ActionResult Index()
        {
            var sachmoi = LaySachMoi(5);
            return View(sachmoi);
        }
    }
}