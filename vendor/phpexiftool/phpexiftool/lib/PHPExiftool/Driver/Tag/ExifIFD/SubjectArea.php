<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\ExifIFD;

use PHPExiftool\Driver\AbstractTag;

class SubjectArea extends AbstractTag
{

    protected $Id = 37396;

    protected $Name = 'SubjectArea';

    protected $FullName = 'Exif::Main';

    protected $GroupName = 'ExifIFD';

    protected $g0 = 'EXIF';

    protected $g1 = 'IFD0';

    protected $g2 = 'Image';

    protected $Type = 'int16u';

    protected $Writable = true;

    protected $Description = 'Subject Area';

    protected $local_g1 = 'ExifIFD';

    protected $local_g2 = 'Camera';

}
