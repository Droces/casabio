<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\Microsoft;

use PHPExiftool\Driver\AbstractTag;

class PanoramicStitchMapType extends AbstractTag
{

    protected $Id = 2;

    protected $Name = 'PanoramicStitchMapType';

    protected $FullName = 'Microsoft::Stitch';

    protected $GroupName = 'Microsoft';

    protected $g0 = 'MakerNotes';

    protected $g1 = 'Microsoft';

    protected $g2 = 'Image';

    protected $Type = 'int32u';

    protected $Writable = true;

    protected $Description = 'Panoramic Stitch Map Type';

    protected $flag_Permanent = true;

    protected $Values = array(
        0 => array(
            'Id' => 0,
            'Label' => 'Perspective',
        ),
        1 => array(
            'Id' => 1,
            'Label' => 'Horizontal Cylindrical',
        ),
        2 => array(
            'Id' => 2,
            'Label' => 'Horizontal Spherical',
        ),
        257 => array(
            'Id' => 257,
            'Label' => 'Vertical Cylindrical',
        ),
        258 => array(
            'Id' => 258,
            'Label' => 'Vertical Spherical',
        ),
    );

}
