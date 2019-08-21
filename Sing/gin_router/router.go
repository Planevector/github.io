package gin_router

import (
   "Sing/gin_api"
    "github.com/gin-gonic/gin"
)

func InitRouter(){
	gin.SetMode(gin.ReleaseMode)
	router :=gin.Default()
	router.NoRoute(gin_api.NotFound)
	v1 :=router.Group("admin")
	{
		v1.GET("/register",gin_api.Register)
		v1.GET("/login",gin_api.Login)
}
router.Run(":8080")
   }
