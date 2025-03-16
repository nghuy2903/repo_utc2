using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Data.Entity;
using testDeThi.Models;

namespace testDeThi.Controllers
{
    
    public class HomeController : Controller
    {

        public QuanLyBanQuanAoEntities db = new QuanLyBanQuanAoEntities();
        public ActionResult Index()
        {
            var all = db.Sanpham.ToList();
            var products = db.PhanLoaiSanPham.Include(sp => sp.Sanpham).ToList();
            ViewBag.AllProducts = all;
            return View(products);
        }
        public ActionResult GetProductsByCategory(int categoryId)
        {
            var products = db.Sanpham
                .Where(s => s.PhanLoaiSanPhamID == categoryId)
                .ToList();

            return PartialView("_ProductListPartial", products);
        }
        public ActionResult About()
        {
            ViewBag.Message = "Your application description page.";

            return View();
        }

        public ActionResult Contact()
        {
            ViewBag.Message = "Your contact page.";

            return View();
        }
    }
}