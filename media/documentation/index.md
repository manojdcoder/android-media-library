# media Module

## Description

Access android media store [Images, Videos, Thumbnails, Audio Files]

## Accessing the media Module

To access this module from JavaScript, you would do the following:

	var media = require("com.mykingdom.media");

The media variable is a reference to the Module object.	

## Reference

TODO: If your module has an API, you should document
the reference here.

### ___PROJECTNAMEASIDENTIFIER__.function

getItems(MediaOption);
getImageThumbnail(ImageId, ThumbnailOption);
getVideoThumbnail(VideoId, ThumbnailOption);
getAlbumArt(AlbumId);

### ___PROJECTNAMEASIDENTIFIER__.property

MEDIA_TYPE_IMAGE
MEDIA_TYPE_VIDEO
MEDIA_TYPE_AUDIO
MEDIA_TYPE_ALL
THUMBANIL_MINI
THUMBANIL_MICRO

## Usage

Refer example\app.js

~~~~~~~~~~~~~~~

var masterWin = Ti.UI.createWindow({
	navBarHidden : false,
	backgroundColor : "#fff"
});
masterWin.open();

var media = require("com.mykingdom.media");

/*
 * MEDIA_TYPE_IMAGE - returns list of images
 * MEDIA_TYPE_VIDEO - returns list of videos
 * MEDIA_TYPE_AUDIO - returns list of audio files
 * MEDIA_TYPE_ALL - returns list of all media items
 *
 * To get only images and videos
 * media.getItems(media.MEDIA_TYPE_IMAGE, media.MEDIA_TYPE_VIDEO);
 */
var list = media.getItems(media.MEDIA_TYPE_ALL);
Ti.API.info(JSON.stringify(list));
/*
 * returned list will have 6 properties
 * images - list of images [Array]
 * imagesCount - total no. of images [Integer]
 * videos - list of videos [Array]
 * videosCount - total no. of videos [Integer]
 * audios - list of audio files [Array]
 * audiosCount - total no. of audio files [Integer]
 */

var table = Ti.UI.createTableView();

/*
 * THUMBANIL_MINI = 96 x 96 JPEG
 * THUMBANIL_MICRO =  512 x 384 JPEG
 */
var imageSection = Ti.UI.createTableViewSection({
	headerTitle : "Images"
});
for (var i = 0; i < list.images.length; i++) {
	var row = Ti.UI.createTableViewRow({
		color : "#000",
		font : {
			fontSize : "20dp",
			fontWeight : "bold"
		},
		title : list.images[i].displayName,
		rowData : list.images[i]
	});
	row.addEventListener("click", function(e) {
		var window = Ti.UI.createWindow({
			navBarHidden : false,
			backgroundColor : "#fff",
			title : "Image Thumbnail"
		});
		window.add(Ti.UI.createImageView({
			image : media.getImageThumbnail(e.row.rowData.id, media.THUMBANIL_MINI)
		}));
		window.open();
	});
	imageSection.add(row);
}

var videoSection = Ti.UI.createTableViewSection({
	headerTitle : "Videos"
});
for (var i = 0; i < list.videos.length; i++) {
	var row = Ti.UI.createTableViewRow({
		color : "#000",
		font : {
			fontSize : "20dp",
			fontWeight : "bold"
		},
		title : list.videos[i].displayName,
		rowData : list.videos[i]
	});
	row.addEventListener("click", function(e) {
		var window = Ti.UI.createWindow({
			navBarHidden : false,
			backgroundColor : "#fff",
			title : "Thumbnail & Images From Video"
		});
		var scrollview = Ti.UI.createScrollView({
			layout : "vertical"
		});
		scrollview.add(Ti.UI.createImageView({
			image : media.getVideoThumbnail(e.row.rowData.id, media.THUMBANIL_MINI)
		}));
		/*
		 * getImageAtTime accepts videoPath & Time in millisecons
		 * the following code gives the image at 5th sec (5000ms) &  10th sec (10000ms)
		 * returns null if video file is in private access
		 */
		scrollview.add(Ti.UI.createImageView({
			image : media.getImageAtTime(e.row.rowData.data, 5000)
		}));
		scrollview.add(Ti.UI.createImageView({
			image : media.getImageAtTime(e.row.rowData.data, 10000)
		}));
		window.add(scrollview);
		window.open();
	});
	videoSection.add(row);
}

var audioSection = Ti.UI.createTableViewSection({
	headerTitle : "Audio"
});
for (var i = 0; i < list.audios.length; i++) {
	var row = Ti.UI.createTableViewRow({
		color : "#000",
		font : {
			fontSize : "20dp",
			fontWeight : "bold"
		},
		title : list.audios[i].displayName,
		rowData : list.audios[i]
	});
	row.addEventListener("click", function(e) {
		var window = Ti.UI.createWindow({
			navBarHidden : false,
			backgroundColor : "#fff",
			title: "Album Art"
		});
		/*
		 * Return null if there is no album art. You can use your own (a default) images
		 */
		var imageView = Ti.UI.createImageView({
			image : media.getAlbumArt(e.row.rowData.albumId)
		});
		window.add(imageView);
		window.open();
	});
	audioSection.add(row);
}

var table = Ti.UI.createTableView({
	data : [imageSection, videoSection, audioSection],
	backgroundColor : "#fff",
	minRowHeight : "75dp"
});
masterWin.add(table);

~~~~~~~~~~~~~~~

## Author

Manoj Kumar. email : mano.mykingdom@gmail.com

## License

Private license.
