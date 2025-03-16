using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace demo_MVC.Controllers
{
    public class HomeController : Controller
    {
        // GET: Home
        public ActionResult Index()//trang xem thông tin sinh viên
        {
            return View();
        }

        public ActionResult Add()//trang thêm mới thông tin sinh viên
        {
            return View();
        }
    }
}