<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\IFD0;

use PHPExiftool\Driver\AbstractTag;

class ResolutionUnit extends AbstractTag
{

    protected $Id = 296;

    protected $Name = 'ResolutionUnit';

    protected $FullName = 'Exif::Main';

    protected $GroupName = 'IFD0';

    protected $g0 = 'EXIF';

    protected $g1 = 'IFD0';

    protected $g2 = 'Image';

    protected $Type = 'int16u';

    protected $Writable = true;

    protected $Description = 'Resolution Unit';

    protected $flag_Mandatory = true;

    protected $Values = array(
        1 => array(
            'Id' => 1,
            'Label' => 'None',
        ),
        2 => array(
            'Id' => 2,
            'Label' => 'inches',
        ),
        3 => array(
            'Id' => 3,
            'Label' => 'cm',
        ),
    );

}
