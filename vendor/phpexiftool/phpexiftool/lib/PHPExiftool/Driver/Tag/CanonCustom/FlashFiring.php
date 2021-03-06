<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\CanonCustom;

use PHPExiftool\Driver\AbstractTag;

class FlashFiring extends AbstractTag
{

    protected $Id = 'mixed';

    protected $Name = 'FlashFiring';

    protected $FullName = 'mixed';

    protected $GroupName = 'CanonCustom';

    protected $g0 = 'MakerNotes';

    protected $g1 = 'CanonCustom';

    protected $g2 = 'Camera';

    protected $Type = 'mixed';

    protected $Writable = true;

    protected $Description = 'Flash Firing';

    protected $flag_Permanent = true;

    protected $Values = array(
        0 => array(
            'Id' => 0,
            'Label' => 'Fires',
        ),
        1 => array(
            'Id' => 1,
            'Label' => 'Does not fire',
        ),
    );

}
