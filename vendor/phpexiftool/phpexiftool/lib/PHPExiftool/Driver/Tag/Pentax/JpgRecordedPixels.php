<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\Pentax;

use PHPExiftool\Driver\AbstractTag;

class JpgRecordedPixels extends AbstractTag
{

    protected $Id = '14.1';

    protected $Name = 'JpgRecordedPixels';

    protected $FullName = 'Pentax::CameraSettings';

    protected $GroupName = 'Pentax';

    protected $g0 = 'MakerNotes';

    protected $g1 = 'Pentax';

    protected $g2 = 'Camera';

    protected $Type = 'int8u';

    protected $Writable = true;

    protected $Description = 'Jpg Recorded Pixels';

    protected $flag_Permanent = true;

    protected $Values = array(
        0 => array(
            'Id' => 0,
            'Label' => '10 MP',
        ),
        1 => array(
            'Id' => 1,
            'Label' => '6 MP',
        ),
        2 => array(
            'Id' => 2,
            'Label' => '2 MP',
        ),
    );

}