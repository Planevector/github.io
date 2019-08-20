package gin_router
import (
    api "Sing/gin_api"
	"net/http"
    "github.com/gin-gonic/gin"
)
func InitRouter(){
	gin.SetMode(gin.ReleaseMode)
	router :=gin.Default()
	router.NoRoute(api.NotFound)
	V1 :=router.Group("admin"){
		v1.GET("/register",api.Register)
		v1.GET("/login",api.Login)
}

   }
