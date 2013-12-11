
/*
 * GET home page.
 */

exports.index = function(req, res){
  console.log("channelNumber: " + req.params.channelNumber);
  
  var movie = "Yif-Magic.mp4";
  switch (req.params.channelNumber * 1) {
  case 18:
    movie = "iron_man-tlr2_h1080p.mov";
	break;
  case 19:
    movie = "5615615659_1080p.mov";
	break;
  case 20:
    movie = "IronMan3_Trailer2_1080.mov";
	break;
  case 21:
    movie = "kickass-tlr4_h1080p.mov";
	break;
  case 45:
    movie = "kickass2-tlr_h1080p.mov";
	break;
  case 65:
    movie = "ironlady-tlr2_h1080p.mov";
	break;
  case 70:
    movie = "28436080_mp4_h264_aac.mp4";
	break;
  }
  
  res.sendfile('./public/video/' + movie);
};
