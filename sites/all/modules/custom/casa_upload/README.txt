CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Installation & Usage


INTRODUCTION
------------

Casa Upload allows you to upload a bunch of images (media files), which will then be used to create pictures (the content type) for each file. The files are selected via a browser file upload dialog, and can be stored in a media entity, file or image field.
Also, default values can be chosen for the other fields assigned to the new nodes.




INSTALLATION & USAGE
------------

1.  Install the Plupload and Token modules. (Dont forget their dependencies!)
2.  Download plupload from plupload.com and copy the files into sites/all/libraries/plupload
3.  Create a content type with at least one media-, image- or file-field
4.  Go to admin/config/media/bulk_media_upload and choose your nodetype and the created media-, image- or file-field
5.  Visit admin/content/media/bulk_upload, fill in the form, and start uploading!
