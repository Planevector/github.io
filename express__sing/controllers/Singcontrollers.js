var bodyParser=require('body-parser');
var urlencodedParser=bodyParser.urlencoded({extended:false});
var mongoose=require('mongoose');
mongoose.connect('mongodb://localhost:27017/sing');

var singSchema=new mongoose.Schema({
    Username:String,
    Password:String
});
var Sing=mongoose.model('Sing',singSchema);


// var ValuesOne=Sing({Username:'sad',Password:'123'}).save(function(err){
//     if(err)throw err;
//     console.log('item');
// });
  

module.exports=function(app){

    app.post('/sing',urlencodedParser,function(req,res){
        var ValuesOne=Sing(req.body).save(function(err,data){
            if(err)throw err;
        });
          
    });
}