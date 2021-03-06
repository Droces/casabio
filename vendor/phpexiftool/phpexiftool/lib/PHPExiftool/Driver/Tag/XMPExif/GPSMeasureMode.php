<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\XMPExif;

use PHPExiftool\Driver\AbstractTag;

class GPSMeasureMode extends AbstractTag
{

    protected $Id = 'GPSMeasureMode';

    protected $Name = 'GPSMeasureMode';

    protected $FullName = 'XMP::exif';

    protected $GroupName = 'XMP-exif';

    protected $g0 = 'XMP';

    protected $g1 = 'XMP-exif';

    protected $g2 = 'Image';

    protected $Type = 'integer';

    protected $Writable = true;

    protected $Description = 'GPS Measure Mode';

    protected $local_g2 = 'Location';

    protected $Values = array(
        2 => array(
            'Id' => 2,
            'Label' => '2-Dimensional',
        ),
        3 => array(
            'Id' => 3,
            'Label' => '3-Dimensional',
        ),
    );

}
