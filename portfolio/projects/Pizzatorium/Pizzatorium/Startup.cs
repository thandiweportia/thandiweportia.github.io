using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(Pizzatorium.Startup))]
namespace Pizzatorium
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
