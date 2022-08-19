using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using MvcMusicStore.Models;

namespace MvcMusicStore.Controllers
{
    public class StoreController : Controller
    {
        public MusicStoreEntities storeDB = new MusicStoreEntities();

        // GET: Store
        public ActionResult Index()
        {
            var genres = storeDB.Genres.ToList();

            return View(genres);
        }

        public ActionResult Browse(string genre)
        {     // Retrieve Genre and its Associated Albums from database     
            var genreModel = storeDB.Genres.Include("Albums")         
                .Single(g => g.Name == genre); 

            return View(genreModel);
        }

        public ActionResult Details(int id)
        {
            var album = storeDB.Albums.Find(id);

            return View(album);
        }


        // // GET: /Store/GenreMenu 

        [ChildActionOnly]
        public ActionResult GenreMenu()
        {
            var genres = storeDB.Genres.ToList();

            return PartialView(genres);
        }

        private List<Album> GetTopSellingAlbums(int count)
        {     
            // Group the order details by album and return     
            // the albums with the highest count 

            return storeDB.Albums.OrderByDescending(a => a.OrderDetails.Count()).Take(count).ToList();
        }
    }
}