<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\Olympus;

use PHPExiftool\Driver\AbstractTag;

class Gradation extends AbstractTag
{

    protected $Id = 1295;

    protected $Name = 'Gradation';

    protected $FullName = 'Olympus::CameraSettings';

    protected $GroupName = 'Olympus';

    protected $g0 = 'MakerNotes';

    protected $g1 = 'Olympus';

    protected $g2 = 'Camera';

    protected $Type = 'int16s';

    protected $Writable = true;

    protected $Description = 'Gradation';

    protected $flag_Permanent = true;

    protected $Values = array(
        '-1 -1 1' => array(
            'Id' => '-1 -1 1',
            'Label' => 'Low Key',
        ),
        '0 -1 1' => array(
            'Id' => '0 -1 1',
            'Label' => 'Normal',
        ),
        '0 0 0' => array(
            'Id' => '0 0 0',
            'Label' => 'n/a',
        ),
        '1 -1 1' => array(
            'Id' => '1 -1 1',
            'Label' => 'High Key',
        ),
    );

}
